#include <vector>
#include <iostream>

#include "util.hh"
#include "device.hh"
#include "config.hh"

using namespace std;

int main()
{
  vector<Device> devices = read_config_file();
  cout << "Read " << devices.size() << " devices\n";

  for (int i = 0; i < int(devices.size()); ++i) {
    unique_ptr<Pipe> p = devices[i].query("IF-MIB::ifNumber.0");
    string line;
    while (getline(p->stream(), line))
      cout << line << '\n';
  }

  return 0;
}
