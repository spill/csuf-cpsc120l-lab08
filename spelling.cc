// Ryan Trinh
// CPSC 120-06
// 2022-10-19
// rtrinh02@csu.fullerton.edu
// @rtrinh02
//
// Lab 09-01
// Partners: @rubenarmenta
//
// Spelling
//

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
std::vector<std::string> ReadWords(const std::string& filename) {
  std::vector<std::string> words;
  std::ifstream input_file_stream{filename};
  std::string word;
  while (input_file_stream >> word) {
    words.push_back(word);
  }
  return words;
}
bool InDictionary(const std::vector<std::string>& dictionary,
                  const std::string& word) {
  for (const std::string& dict_word : dictionary) {
    if (dict_word == word) {
      return true;
    }
  }
  return false;
}
std::vector<std::string> MisspelledWords(
    const std::vector<std::string>& dictionary,
    const std::vector<std::string>& document) {
  std::vector<std::string> misspelled_words;
  for (const std::string& doc_word : document) {
    if (!InDictionary(dictionary, doc_word)) {
      misspelled_words.push_back(doc_word);
    }
  }
  return misspelled_words;
}
int main(int argc, char* argv[]) {
  std::vector<std::string> arguments(argv, argv + argc);
  if (arguments.size() != 2) {
    std::cout << "error: you must give a document filename\n";
    return 1;
  }
  std::string document{arguments.at(1)};
  std::vector<std::string> dictionary = ReadWords("words.txt");
  std::vector<std::string> document_words = ReadWords(document);
  std::vector<std::string> misspelled_words =
      MisspelledWords(dictionary, document_words);
  std::cout << "spelling errors:\n";
  for (const std::string& word : misspelled_words) {
    std::cout << word << "\n";
  }
  return 0;
}
