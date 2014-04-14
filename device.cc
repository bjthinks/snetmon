#include <string>

#include "device.hh"

using namespace std;

Device::Device(const std::string &h, const std::string &c)
  : hostname(h),
    community(c)
{}
