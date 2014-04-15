#include <string>

#include "util.hh"
#include "device.hh"

using namespace std;

unique_ptr<Pipe> Device::query(const string &q)
{
  string command = "snmpbulkwalk -Oq -v2c -c" + community + ' '
    + hostname + ' ' + q;
  return unique_ptr<Pipe>(new Pipe(command));
}

template <typename T>
void Device::setOnInterfaces(const string &q,
                             void (Interface::*setter)(const T &))
{
  // Query the SNMP agent and read its response line by line
  unique_ptr<Pipe> p = query(q);
  string line;
  while (getline(p->stream(), line)) {
    // Assume the response is of the following form:
    // "Blahblah.<interface number> <value>"
    //          ^                  ^        parse it using these delimiters
    pair<string, string> line_parts = split(line);
    string first_word = line_parts.first;
    string rest_of_line = line_parts.second;
    vector<string> first_word_parts = words(first_word, ".");

    // If there was more than one '.' in the first word, ignore
    // the line. Otherwise, set a value on the interface number.
    if (first_word_parts.size() == 2) {
      int interface = stoi(first_word_parts[1]);
      interfaces.at(interface).setGeneric(rest_of_line, setter);
    }
  }
}

// Explicit template instantiations
template void Device::setOnInterfaces<string>
(const string &q, void (Interface::*setter)(const string &));
template void Device::setOnInterfaces<int64_t>
(const string &q, void (Interface::*setter)(const int64_t &));
