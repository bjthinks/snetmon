#ifndef COUNTER_HH
#define COUNTER_HH

class Counter
{
public:
  void operator=(const int64_t &val)
  {
    previous_value = last_value;
    last_value = val;
  }
  operator int64_t() const { return last_value; }

  int64_t lastIntervalCounts() const { return last_value - previous_value; }

private:
  int64_t last_value, previous_value;
};

#endif
