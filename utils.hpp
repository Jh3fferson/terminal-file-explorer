#pragma once
#include <string>
#include <vector>

void enableAnsiEscapeCodes();
int wrapIndex(const int& index, const int& max);
bool commandSelect(int ch, int &index, std::string& path, const std::vector<std::string>& itens);