#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <conio.h>
#include "file_manager.hpp"
#include "utils.hpp"

int main()
{
    system("cls");
    enableAnsiEscapeCodes();

    std::string currentPath = "C:/";
    std::vector<std::string> itens;
    bool loop = true;
    int index = 0;

    while (loop){
        std::cout << "\nCommands: Enter - Open Folder | Backspace - Go Back | n - New | Delete - Delete | Esc - Exit\n";
        std::cout << "\nCurrent Path: " << currentPath << "\n";
        itens = listDirectory(currentPath, index);

        loop = commandSelect(getch(), index, currentPath, itens);
        
        
        system("cls");
    }

    return 0;
}
