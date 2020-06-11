#pragma once
#include <vector>
#include <string>
#include <map>

class Text
{
public:
  void readText();
  void recordReferences();
  void removeSingleWords();
  void findLinks();
  void eraseLinksFromText();
  void printReferences();
  void printWordCounts();
  void printLinks();
private:
  std::vector<std::string> text;
  std::map<std::string, std::vector<int>> wordReferences;
  std::vector<std::string> links;
};