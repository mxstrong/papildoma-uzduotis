#include "Text.h"
#include <algorithm>
#include <utility>
#include <sstream>
#include <map>
#include <iterator>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <filesystem>

bool notPartOfWord(int charCode)
{
  return std::ispunct(charCode) || charCode < 0 || charCode > 127;
}

void Text::recordReferences()
{
  for (int i = 0; i < text.size(); ++i)
  {
    std::string line;
    std::remove_copy_if(text[i].begin(), text[i].end(), std::back_inserter(line), notPartOfWord);
    std::istringstream textInLine(line);
    while (!textInLine.eof())
    {
      std::string word;
      textInLine >> word;
      if (!word.empty())
      {
        auto wordIterator = this->wordReferences.find(word);
        if (wordIterator == this->wordReferences.end()) 
        {
          this->wordReferences.insert(std::pair<std::string, std::vector<int>>(word, { i + 1 }));
        }
        else
        {
          wordIterator->second.push_back(i + 1);
        }
      }
    }
  }
}

void Text::removeSingleWords()
{
  auto iterator = this->wordReferences.begin();
  auto end = this->wordReferences.end();
  for (; iterator != end; )
  {
    if (iterator->second.size() < 2) 
    {
      iterator = this->wordReferences.erase(iterator);
    }
    else {
      ++iterator;
    }
  }
}

void Text::findLinks()
{
  for (auto line : this->text)
  {
    std::istringstream textInLine(line);
    while (!textInLine.eof())
    {
      std::string part;
      textInLine >> part;
      if (part.length() > 5 && (part.rfind("http", 0) == 0 || part.rfind("www", 0) == 0))
      {
        this->links.push_back(part);
      }
    }
  }
}

void Text::eraseLinksFromText()
{
  for (const auto link : this->links)
  {
    for (auto& line : this->text)
    {
      size_t position = std::string::npos;

      while ((position = line.find(link)) != std::string::npos)
      {
        line.erase(position, link.length());
      }
    }
  }
}

void Text::readText()
{
  std::string fileName;
  bool fileExists = false;
  while (!fileExists)
  {
    std::cout << "Iveskite tekstinio failo pavadinima:" << std::endl;
    std::cin >> fileName;
    fileExists = std::filesystem::exists(fileName);
    if (!fileExists)
    {
      std::cout << "Failas tokiu pavadinimu neegzistuoja!" << std::endl;
    }
  }
  std::ifstream in(fileName.c_str());
  while (!in.eof())
  {
    std::string line;
    std::getline(in, line);
    if (!line.empty())
    {
      this->text.push_back(line);
    }
  }
  in.close();
}

void Text::printReferences()
{
  std::ofstream out("references.txt");
  out << std::left << std::setw(20) << "Zodis" << std::setw(20) << "Eilutes kuriose jis paminetas" << std::endl;
  for (const auto& reference : this->wordReferences)
  {
    if (reference.first.find("'") != std::string::npos)
    {
      out << std::left << std::setw(22) << reference.first;
    }
    out << std::left << std::setw(20) << reference.first;
    for (const auto& line : reference.second)
    {
      out << std::left << std::setw(4) << line;
    }
    out << std::endl;
  }
  out.close();
}

void Text::printWordCounts()
{
  std::ofstream out("wordCounts.txt");
  out << std::left << std::setw(20) << "Zodis" << std::setw(4) << "Jo pasikartojimu kiekis tekste" << std::endl;
  for (const auto& word : this->wordReferences)
  {
    if (word.first.find("'") != std::string::npos)
    {
      out << std::left << std::setw(22) << word.first << std::setw(4) << word.second.size() << std::endl;
    }
    out<< std::left << std::setw(20) << word.first << std::setw(4) << word.second.size() << std::endl;
  }
  out.close();
}

void Text::printLinks()
{
  std::ofstream out("links.txt");
  for (const auto link : this->links)
  {
    out << link << std::endl;
  }
  out.close();
}
