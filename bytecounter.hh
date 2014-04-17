#ifndef BYTECOUNTER_HH
#define BYTECOUNTER_HH

class ByteCounter
{
public:
  void operator=(const int64_t &val) { bytes = val; }
  operator int64_t() const { return bytes; }

private:
  int64_t bytes;
};

#endif
