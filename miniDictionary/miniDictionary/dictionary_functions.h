#pragma once
#include <iostream>
#include <map>
#include <fstream>
#include <string>

using Dictionary = std::map <std::string, std::string>;

Dictionary GetDictionaryFrom(std::string & fileName);
bool DictionaryContainsTranslationOf(const std::string & word, const Dictionary & dictionary);
std::string GetTranslationOf(const std::string & word, const Dictionary & dictionary);
void InsertNewWordInto(const std::string & word, Dictionary & dictionary);