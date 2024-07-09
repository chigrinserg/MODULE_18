#pragma once
#include <iostream>
#include <fstream>
#include <filesystem> 

namespace fs = std::filesystem;
void demo_perms(std::filesystem::perms p) {} //�������-����������� ������������ ���� �������

void Settings() //������� ����� � ������������ ��������� ���� ������� 
{
    int cnt{};
    std::cout << "��� ������������ ���� ������� � ������ ����� �������� ������� ��������������." << '\n';
    std::cout << "������� ����������� ������ : ";
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
            std::cout << "����� ������� � ������ �����������! " << '\n';
            std::cout << '\n';
            break;
        }
        else
        {
            std::cout << "�������� ������! ";
            ++cnt;
        }
    } while (cnt < 3);
    if (cnt == 3)
    {
        std::cout << '\n';
        std::cout << " -----------------------------------------------------------------------" << '\n';
        std::cout << "|       ������ ������ ������� ��� ����. ��������� ���������� ������.     |" << '\n';
        std::cout << " -----------------------------------------------------------------------" << '\n';
        exit(0);
    }
}

