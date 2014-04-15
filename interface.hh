#ifndef INTERFACE_HH
#define INTERFACE_HH

#include <string>

class Interface
{
public:
  void setName(const std::string &s) { name_ = s; }
  void setAlias(const std::string &s) { alias_ = s; }
  void setDescription(const std::string &s) { description_ = s; }
  const std::string &name() const { return name_; }
  const std::string &alias() const { return alias_; }
  const std::string &description() const { return description_; }

private:
  std::string name_;
  std::string alias_;
  std::string description_;
};

#endif
