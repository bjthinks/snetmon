#include <string>
#include <vector>
#include <fstream>
#include <iostream>

#include "util.hh"
#include "config.hh"

using namespace std;

void read_config_file()
{
  const string config_name = string(getenv("HOME")) + "/.snetmon";
  ifstream config_file(config_name.c_str());

  string line;
  int line_number = 0;
  while (getline(config_file, line)) {
    ++line_number;
    vector<string> parsed_line = words(line);
    if (parsed_line.size() == 0)
      continue;
    if (parsed_line[0][0] == '#')
      continue;
    const string &command = parsed_line[0];
    if (command == "device") {
      // Get the hostname
      if (parsed_line.size() == 1) {
        cerr << config_name << ": " << line_number
             << ": device is missing hostname\n";
        exit(1);
      }
      const string &hostname = parsed_line[1];

      // Get the "community", aka password
      if (parsed_line.size() == 2) {
        cerr << config_name << ": " << line_number
             << ": device " << hostname << " is missing community\n";
        exit(1);
      }
      const string &community = parsed_line[2];

      cout << "Got device, hostname " << hostname << ", community "
           << community << '\n';
    } else {
      cerr << config_name << ": " << line_number
           << ": unrecognized command: " << command << '\n';
      exit(1);
    }
  }
}
