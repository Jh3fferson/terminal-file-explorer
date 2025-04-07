#include "file_manager.hpp"
#include "utils.hpp"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <vector>
#include <windows.h>
#include <conio.h>

std::vector<std::string> listDirectory(const std::string& path, int& index) {
    std::vector<std::string> itens;
    constexpr int windowSize = 20;

    try {
        for (const auto& entry : std::filesystem::directory_iterator(path)) {
            const auto entryPath = entry.path();
            const std::string name = entryPath.filename().string();
            const std::string fullPath = entryPath.string();

            // Se for diretório, testa permissão
            if (entry.is_directory()) {
                HANDLE hDir = CreateFileA(
                    fullPath.c_str(),
                    GENERIC_READ,
                    FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE,
                    nullptr,
                    OPEN_EXISTING,
                    FILE_FLAG_BACKUP_SEMANTICS,
                    nullptr
                );
                if (hDir == INVALID_HANDLE_VALUE) {
                    continue;
                }
                CloseHandle(hDir);
            }

            itens.push_back(name);
        }

        int total = static_cast<int>(itens.size());
        if (total == 0) return itens;

        // Corrige index fora do intervalo
        if (index < 0) index = 0;
        if (index >= total) index = total - 1;

        // Calcula janela visível
        int start = std::max(0, index - windowSize / 2);
        int end = std::min(start + windowSize, total);
        if (end - start < windowSize && start > 0) {
            start = std::max(0, end - windowSize);
        }

        // Exibe itens visíveis
        for (int i = start; i < end; ++i) {
            bool isSelected = (i == index);

            if (isSelected) std::cout << "\033[30;47m"; 

            std::cout << (isSelected ? "> " : "  ")
                      << " : " << (std::filesystem::is_directory(path + "/" + itens[i]) ? "[DIR]  " : "[FILE]  ")
                      << itens[i];

            if (isSelected) std::cout << "\033[0m"; 

            std::cout << '\n';
        }

    } catch (const std::filesystem::filesystem_error& e) {
        std::cout << "Error accessing directory: " << e.what() << '\n';
    }

    return itens;
}


void open(std::string& path, const std::string& item, int& index){
    std::filesystem::path p(path);
    if (!std::filesystem::exists(p)) {
        std::cout << "This file or folder don't exist.\n";
        return;
    }
    p /= item;
    std::string openedPath = p.string();
    if (std::filesystem::is_directory(openedPath)) {
        path = openedPath;
        index = 0;
    } else {
        ShellExecuteA(NULL, "open", openedPath.c_str(), NULL, NULL, SW_SHOW);
    }
}

void closeFolder(std::string& path){
    std::filesystem::path p(path);
    p = p.parent_path();
    path = p.string();
}

void createNew(const std::string& path){

    std::cout << "Enter Name: ";
    std::string newName;
    std::cin >> newName;

    size_t pos = newName.rfind('.');
    if (pos != std::string::npos && pos != newName.length() - 1) {
        std::ofstream arquivo(path+"/"+newName);
    }
    else{
        std::filesystem::create_directory(path + "/" + newName);
    }
}

void deleteSomething(const std::string& path, const std::string& item){

    if(std::filesystem::remove_all(path + "/" + item)){
        std::cout << "deleted with sucess";
    }else{
        std::cout << "This file or folder don't exist.";
    }
}
