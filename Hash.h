#pragma once
#include <iostream>
#include <string>
#include <unordered_map>

class Hash
{
private:
    std::string m_login;
    std::string m_pass;
    std::unordered_map<std::string, std::string> list_of_passes; //���-������� ���������� ������� � ������� �������������

public:
    Hash() {};
    Hash(std::string login, std::string pass);
    std::unordered_map<std::string, std::string>::iterator it;

    bool on_guard(std::string password); //������ �� ������
    void fillMap(std::string login, std::string password);   //������� ���������� ���-�������
    void extractMap();                             //���������� ������� �� �����
    int countPasses(const std::string name_file);  //������� ����� ����� � ��������� ����� �������
    std::string getpass(int n);                    //���������� �� ����� ������� ��� �������� � ���-�������
    std::string getLogin(int n);                              //���������� �� ����� ������ ������� ��� �������� � ���-�������
    void print();
    ~Hash() {};
};
