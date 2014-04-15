#ifndef UTIL_HH
#define UTIL_HH

#include <string>
#include <vector>
#include <cstdio>
#include <istream>
#include <ext/stdio_filebuf.h>

// Splits a string before/after the first delimiter character
std::pair<std::string, std::string>
split(const std::string &str, const char *delimiters = " \t");

// Repeatedly splits a string and returns a vector of its
// nonempty words.
std::vector<std::string>
words(const std::string &str, const char *delimiters = " \t");

// Run a command via the shell, and provide the output as a C++
// istream object. Uses GNU C++ extensions, since there appears
// to be no fully portable way to do this.
class Pipe
{
public:
  Pipe(const std::string &command);
  ~Pipe();

  std::istream &stream()
  {
    return pipe_as_stream;
  }

private:
  FILE *pipe_as_file;
  __gnu_cxx::stdio_filebuf<char> pipe_as_filebuf;
  std::istream pipe_as_stream;
};

#endif
