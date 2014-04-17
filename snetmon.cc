#include <vector>
#include <iostream>
#include <unistd.h>

#include "util.hh"
#include "device.hh"
#include "config.hh"

using namespace std;

int main()
{
  vector<Device> devices = read_config_file();

  for (;;) {
    sleep(5);
    for (int d = 0; d < int(devices.size()); ++d) {
      Device &device = devices[d];
      device.update();
      Interface &interface = device[1];
      const ByteCounter &counter = interface.bytesIn();
      cout << counter.lastUpdateTime() << ','
           << counter.lastUpdateBPS() << '\n';
    }
  }

  return 0;
}
