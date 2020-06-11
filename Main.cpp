#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Text.h"

int main()
{
  Text text;
  text.readText();
  text.findLinks();
  text.eraseLinksFromText();
  text.recordReferences();
  text.removeSingleWords();
  text.printWordCounts();
  text.printReferences();
  text.printLinks();
  return 0;
}