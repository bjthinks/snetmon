#include <vector>
#include <iostream>

#include "util.hh"
#include "device.hh"
#include "config.hh"

using namespace std;

int main()
{
  vector<Device> devices = read_config_file();

  for (int d = 0; d < int(devices.size()); ++d) {
    Device &device = devices[d];

    // Add all of the extant Interfaces to this Device
    unique_ptr<Pipe> p = device.query("IF-MIB::ifIndex");
    string line;
    while (getline(p->stream(), line)) {
      vector<string> line_words = words(line);
      if (line_words.size() == 2) {
        int i = stoi(line_words[1]);
        device.addInterface(i);
      }
    }

    // Query and set values
    device.setOnInterfaces("IF-MIB::ifName", &Interface::setName);
    device.setOnInterfaces("IF-MIB::ifAlias", &Interface::setAlias);
    device.setOnInterfaces("IF-MIB::ifDescr", &Interface::setDescription);
    device.setOnInterfaces("IF-MIB::ifHCInOctets", &Interface::setBytesIn);
    device.setOnInterfaces("IF-MIB::ifHCOutOctets", &Interface::setBytesOut);

    // Print them
    Device::iterator i;
    for (i = device.begin(); i != device.end(); ++i) {
      int interface_number = i->first;
      Interface &interface = i->second;
      cout << interface_number
           << ": Name=\'" << interface.name()
           << "\' Alias=\'" << interface.alias()
           << "\' Description=\'" << interface.description()
           << "\' BytesIn=" << interface.bytesIn()
           << " BytesOut=" << interface.bytesOut()
           << "\n";
    }
  }

  return 0;
}
