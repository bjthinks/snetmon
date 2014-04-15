#ifndef INTERFACE_HH
#define INTERFACE_HH

#include <string>

class Interface
{
public:
  // Setters
  void setName(const std::string &s) { name_ = s; }
  void setAlias(const std::string &s) { alias_ = s; }
  void setDescription(const std::string &s) { description_ = s; }
  void setBytesIn(const int64_t &b) { bytesIn_ = b; }
  void setBytesOut(const int64_t &b) { bytesOut_ = b; }

  // Corresponding getters
  const std::string &name() const { return name_; }
  const std::string &alias() const { return alias_; }
  const std::string &description() const { return description_; }
  const int64_t bytesIn() const { return bytesIn_; }
  const int64_t bytesOut() const { return bytesOut_; }

private:
  std::string name_;
  std::string alias_;
  std::string description_;
  int64_t bytesIn_;
  int64_t bytesOut_;
};

#endif
