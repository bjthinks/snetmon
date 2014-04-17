#ifndef COUNTER_HH
#define COUNTER_HH

#include <ctime>

class Counter
{
public:
  void operator=(const int64_t &val)
  {
    previous_value = last_value;
    last_value = val;
    previous_time = last_time;
    last_time = time(NULL);
  }
  operator int64_t() const { return last_value; }

  time_t lastUpdateTime() const { return last_time; }
  int64_t lastUpdateCountsPerSecond() const
  {
    return (last_value - previous_value)
      / int64_t(last_time - previous_time);
  }

private:
  int64_t last_value, previous_value;
  time_t last_time, previous_time;
};

#endif
