#include "util.hh"

using namespace std;

pair<string, string> split(const string &str, const char *delimiters)
{
  size_t pos = str.find_first_of(delimiters);

  if (pos == string::npos)
    return make_pair(str, string());

  return make_pair(str.substr(0, pos), str.substr(pos + 1, string::npos));
}

vector<string> words(const string &str, const char *delimiters)
{
  // Invariant: all words that come before current_position are in the
  // result vector.
  vector<string> result;
  size_t current_position = 0;

  do {
    // Search for a word in the remaining part of the string.
    size_t word_start = str.find_first_not_of(delimiters, current_position);

    // If the rest of the string was all delimiters, we're done.
    if (word_start == string::npos)
      break;

    // Search for a delimiter after the new word.
    size_t word_end = str.find_first_of(delimiters, word_start);

    // If we reached the end of the string, the word is the remainder
    // of the string. Otherwise, the word has length = (end - start).
    string word = str.substr(word_start, word_end == string::npos
                             ? string::npos : word_end - word_start);

    // Store the word, advance beyond it, and continue as needed.
    result.push_back(word);
    current_position = word_end;
  } while (current_position != string::npos);

  return result;
}

Pipe::Pipe(const string &command)
  : pipe_as_file(popen(command.c_str(), "r")),
    pipe_as_filebuf(pipe_as_file, ios::in),
    pipe_as_stream(&pipe_as_filebuf)
{}

Pipe::~Pipe()
{
  pclose(pipe_as_file);
}

string prettytime(time_t t)
{
  struct tm *tm_data = localtime(&t);

  const char *format = "%Y-%m-%d %H:%M:%S %z";
  // Length calculation: "2014-01-01 12:00:00 -0600" --> 25 characters
  char buf[32];
  strftime(buf, 32, format, tm_data);

  return string(buf);
}
