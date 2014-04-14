#include "util.hh"

using namespace std;

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
