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

    unique_ptr<Pipe> p = device.query("IF-MIB::ifIndex");
    string line;
    while (getline(p->stream(), line)) {
      vector<string> line_words = words(line);
      if (line_words.size() == 2) {
        int i = stoi(line_words[1]);
        device.addInterface(i);
      }
    }

    Device::iterator i;
    for (i = device.begin(); i != device.end(); ++i) {
      int interface_number = i->first;
      cout << interface_number << '\n';
    }
  }

  return 0;
}
