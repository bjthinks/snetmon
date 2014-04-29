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
    sleepUntilNextMinute();
    for (int d = 0; d < int(devices.size()); ++d) {
      Device &device = devices[d];
      device.update();
      Interface &interface = device[1];
      const Counter &counter = interface.bytesIn();
      cout << prettytime(counter.lastUpdateTime()) << ','
           << counter.lastUpdateCountsPerSecond() * 8 << '\n';
    }
  }

  return 0;
}
