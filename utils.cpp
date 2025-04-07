#include "utils.hpp"
#include "file_manager.hpp"
#include <windows.h>
#include <string>
#include <vector>
#include <conio.h>
#include <iostream>
#include <filesystem>

void enableAnsiEscapeCodes() {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, dwMode);
}

int wrapIndex(const int& index, const int& max) {
    return (index % max + max) % max;
}

bool commandSelect(int ch, int &index, std::string& path, const std::vector<std::string>& itens){
    if (ch == 0 || ch == 224) { // tecla especial
        int specialKey = getch();
        switch (specialKey) {
            case 72: index--; break;
            case 80: index++; break;
            case 83: 
                deleteSomething(path, itens[index]); 
                system("pause");
                break;
        }
        if (!itens.empty()) {
            index = wrapIndex(index, static_cast<int>(itens.size()));
        }            
    } else {
        if (ch == 13){
            open(path, itens[index], index);
        } 
        if (ch == 8){
            closeFolder(path);
            system("pause");
            index=0;
        }
        if (ch == 'n' || ch == 'N') {
            createNew(path);
            system("pause");
        }
        if (ch == 27) return false; // ESC = sair
    }
    return true;
}
