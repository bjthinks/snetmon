#ifndef DEVICE_HH
#define DEVICE_HH

#include <memory>
#include <string>

class Device
{
public:
  Device(const std::string &h, const std::string &c);
  std::unique_ptr<Pipe> query(const std::string &q);

private:
  std::string hostname;
  std::string community;
};

#endif
