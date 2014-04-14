#include <vector>
#include <iostream>

#include "device.hh"
#include "config.hh"

using namespace std;

int main()
{
  vector<Device> devices = read_config_file();
  cout << "Read " << devices.size() << " devices\n";

  return 0;
}
