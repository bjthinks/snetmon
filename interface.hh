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

  // Set a value by providing a string and one of the above setters
  template <typename T>
  void setGeneric(const std::string &val,
                  void (Interface::*setter)(const T &));

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

// Template specializations for setting various types of values

template <> inline void Interface::setGeneric<std::string>
(const std::string &val, void (Interface::*setter)(const std::string &))
{
  (this->*setter)(val);
}

template <> inline void Interface::setGeneric<int64_t>
(const std::string &val, void (Interface::*setter)(const int64_t &))
{
  (this->*setter)(stoll(val));
}

#endif
