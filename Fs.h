#pragma once
#include <iostream>
#include <fstream>
#include <filesystem> 

namespace fs = std::filesystem;
void demo_perms(std::filesystem::perms p) {} //функция-конструктор установления прав доступа

void Settings() //функция входа в подпрограмму установки прав доступа 
{
    int cnt{};
    std::cout << "Для установления прав доступа к файлам нужно обладать правами админимтратора." << '\n';
    std::cout << "Введите специальный пароль : ";
    do
    {
        std::string pas = "qwertyqwerty";
        std::string password;
        std::cin >> password;
        if (password == pas)
        {
            std::cout << '\n';
            fs::permissions("ListOfUsers.txt", fs::perms::owner_read | fs::perms::owner_write | fs::perms::group_read | fs::perms::group_write | fs::perms::others_read | fs::perms::others_write);
            demo_perms(fs::status("ListOfUsers.txt").permissions());

            fs::permissions("Messages.txt", fs::perms::owner_read | fs::perms::owner_write | fs::perms::group_read | fs::perms::group_write | fs::perms::others_read | fs::perms::others_write);
            demo_perms(fs::status("Messages.txt").permissions());

            fs::permissions("hashTable.txt", fs::perms::owner_read | fs::perms::owner_write | fs::perms::group_read | fs::perms::group_write | fs::perms::others_read | fs::perms::others_write);
            demo_perms(fs::status("hashTable.txt").permissions());
            std::cout << "Права доступа к файлам установлены! " << '\n';
            std::cout << '\n';
            break;
        }
        else
        {
            std::cout << "Неверный пароль! ";
            ++cnt;
        }
    } while (cnt < 3);
    if (cnt == 3)
    {
        std::cout << '\n';
        std::cout << " -----------------------------------------------------------------------" << '\n';
        std::cout << "|       Пароль введен неверно три раза. Программа прекращает работу.     |" << '\n';
        std::cout << " -----------------------------------------------------------------------" << '\n';
        exit(0);
    }
}

