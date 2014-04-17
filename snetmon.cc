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

    // Print the initial data
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
