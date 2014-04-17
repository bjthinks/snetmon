#ifndef BYTECOUNTER_HH
#define BYTECOUNTER_HH

#include <ctime>

class ByteCounter
{
public:
  void operator=(const int64_t &val)
  {
    previous_bytes = last_bytes;
    last_bytes = val;
    previous_time = last_time;
    last_time = time(NULL);
  }
  operator int64_t() const { return last_bytes; }

  time_t lastUpdateTime() const { return last_time; }
  float lastUpdateBPS() const
  {
    return float(last_bytes - previous_bytes)
      / float(last_time - previous_time);
  }

private:
  int64_t last_bytes, previous_bytes;
  time_t last_time, previous_time;
};

#endif
