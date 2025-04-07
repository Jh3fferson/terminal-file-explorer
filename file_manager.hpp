#pragma once
#include <string>
#include <vector>

std::vector<std::string> listDirectory(const std::string& path, int& index);
void closeFolder(std::string& path);
void open(std::string& path, const std::string& item, int& index);
void createNew(const std::string& path);
void deleteSomething(const std::string& path, const std::string& item);