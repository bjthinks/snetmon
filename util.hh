#ifndef UTIL_HH
#define UTIL_HH

#include <string>
#include <vector>

// Return a vector of all nonempty maximal substrings of non-delimiter
// characters (i.e. "words"), in order of occurrence.
std::vector<std::string>
words(const std::string &str, const char *delimiters = " \t");

#endif
