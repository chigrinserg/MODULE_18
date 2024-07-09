#include <iostream>
#include "Hash.h"
#include <string>
#include <unordered_map>
#include <vector>
#include <fstream>
#include <ios>
#include <algorithm>

Hash::Hash(std::string pass, std::string login) : m_pass(pass), m_login(login) {};

void Hash::print() //����� ���-������� �� �������. ������������ ������ ��� ������������ ���������
{
    for (it = list_of_passes.begin(); it != list_of_passes.end(); ++it)
    {
        std::cout << it->first << " - " << it->second << '\n';
    }
}

void Hash::fillMap(std::string password, std::string login) //���������� ������� ��� ����������� ������������
{
    list_of_passes.insert({ password,  login });
    std::ofstream out("hashTable.txt", std::ios::app);

    for (it = list_of_passes.begin(); it != list_of_passes.end(); ++it)
    {
        std::cout << "��� ������: " << it->first << "   ��� �����: " << it->second << '\n';
        std::cout << '\n';
        out << it->first << " " << it->second << '\n';
    }
}

void Hash::extractMap() //�������� � ������� ������, ����������� � ��������� �����
{
    int n = countPasses("hashTable.txt") - 1;
    for (int i = 0; i < n; ++i)
    {
        list_of_passes.insert({ getpass(i), getLogin(i)});
    }
    std::cout << '\n';
    if (list_of_passes.empty() == 0)
    {
        return;
    }
}

int Hash::countPasses(const std::string name_file) //������� ����� ����� � ����� 
{
    int numPasses = 0;
    std::ifstream input_file("hashTable.txt");
    std::string s;
    while (!input_file.eof())
    {
        std::getline(input_file, s);
        ++numPasses;
    }
    input_file.close();
    return numPasses;
}

int sizemass = 0;
std::vector<std::string> arr_pass(sizemass); //��������������� ������ ������ ������� �� ���������� �����
int sizemass2 = 0;
std::vector<std::string> arr_log(sizemass2); //���������������� ������ ������ ��������

std::string Hash::getpass(int n) //������� ���������� �� ����� ������ ������� ��� �������� ���-�������
{
    std::string line;
    std::string str_pass;
    std::ifstream in("hashTable.txt"); // �������� ���� ��� ������
    if (in.is_open())
    {
        while (std::getline(in, line))
        {
            str_pass = line.substr(0, 8); //��������� �� ������ ��������� ������
            arr_pass.push_back(str_pass); //��������� �� ��������������� ������ arr_pass
            ++sizemass;
        }
    }
    in.close();     // ��������� ����
    return arr_pass[n];
}

std::string Hash::getLogin(int n) //������� ���������� �� ����� ������ ������� ��� �������� ���-������� ��� ������� ���������
{
    std::string line;
    std::string id;
    std::ifstream inn("hashTable.txt"); // �������� ���� ��� ������
    if (inn.is_open())
    {
        while (std::getline(inn, line))
        {
            id = line.substr(9);        //��������� �� ������ ��������� ������ 
            arr_log.push_back(id); //��������� � arr_log
            ++sizemass2;
        }
    }
    inn.close();     // ��������� ����
    return arr_log[n];
}

bool Hash::on_guard(std::string password) //������ ������������ � ��� �� ������
{
        std::string it_second;
        it = list_of_passes.find(password);
        if (it != list_of_passes.end())
        {
            return true;
        }
        else
        {
            std::cout << "�������� ������" << '\n';
            return false;
        }
}

