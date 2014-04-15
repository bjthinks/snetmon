#ifndef DEVICE_HH
#define DEVICE_HH

#include <memory>
#include <string>
#include <map>

#include "interface.hh"

class Device
{
public:
  Device(const std::string &h, const std::string &c)
    : hostname(h),
      community(c)
  {}
  std::unique_ptr<Pipe> query(const std::string &q);

  void addInterface(int i)
  {
    // Accessing an entry of a map will cause a new entry to be
    // default-constructed if one doesn't already exist.
    interfaces[i];
  }
  // The following lets us use the Device as if it were a limited
  // functionality map<int, Interface>.
  typedef std::map<int, Interface>::iterator iterator;
  Interface &operator[](int i)
  {
    // map::at() accesses an existing element of a map, but throws
    // an exception if the entry doesn't exist.
    return interfaces.at(i);
  }
  iterator begin()
  {
    return interfaces.begin();
  }
  iterator end()
  {
    return interfaces.end();
  }

private:
  std::string hostname;
  std::string community;
  std::map<int, Interface> interfaces;
};

#endif