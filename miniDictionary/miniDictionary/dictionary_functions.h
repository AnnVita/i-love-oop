#pragma once
#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <utility>

using Dictionary = std::map <std::string, std::string>;
static const std::string EXIT_STRING = "...";

void ProcessProgramLoop(Dictionary & dictionary, std::istream & input, std::ostream & output);
void ProcessUserEntries(Dictionary & dictionary, const std::string & userEntries, std::istream & input, std::ostream & output);

bool GetDictionaryFromFile(const std::string & fileName, Dictionary & newDictionary);
void FillDictionaryFrom(std::istream & input, Dictionary & newDictionary);
std::string GetTranslationOf(const std::string & word, const Dictionary & dictionary);
void InsertNewWordIntoDictionary(const std::string & word, const std::string & translation, Dictionary & dictionary);

void ProcessDictionaryRetention(Dictionary & dictionary, const std::string & fileName, std::istream & input, std::ostream & output);
void SaveDictionaryTo(std::ostream & destination, Dictionary & dictionary);