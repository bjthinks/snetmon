#include <string>

#include "util.hh"
#include "device.hh"

using namespace std;

unique_ptr<Pipe> Device::query(const string &q)
{
  return unique_ptr<Pipe>(new Pipe(string("snmpbulkwalk -Oq -v2c -c")
                                   + community + ' ' + hostname + ' ' + q));
}
