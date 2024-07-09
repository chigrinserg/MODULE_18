#pragma once
#include <iostream>
#include <string>
#include <vector>

class User
{
private:
    std::string m_log;
    std::string m_name;

public:
    User() {};
    User(std::string& log, std::string& name);

    std::vector<User> list_of_users;

    void setUsers(std::string log, std::string name);
    void getUsers(); //����� ������������ �� ������� ��� �����������
    void getListUsers();//�������� ������������� ������ ���������
    std::string getLogins(); //���������� �������
    std::string getNames(); //���������� ����
    void FillArray(std::string login, std::string name); //����������� ������ ������������
    static int Get_records_in_file(const std::string name_file);
    void getListUsers_from_file(); //������� ���������� ������ ������������� �� �����
                                                  //��� ������� � ���������
    void DeleteEmptyLines(std::string file); //�������� ������ ����� �� ����� �������
    friend std::ostream& operator<< (std::ostream& out, const User& user);
    friend std::istream& operator>> (std::istream& in, User& user);
    ~User() {};
};
