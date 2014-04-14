#ifndef DEVICE_HH
#define DEVICE_HH

#include <string>

class Device
{
public:
  Device(const std::string &h, const std::string &c);

private:
  std::string hostname;
  std::string community;
};

#endif
