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
    void getUsers(); //вывод пользователя на консоль при регистрации
    void getListUsers();//просмотр пользователем списка контактов
    std::string getLogins(); //извлечение логинов
    std::string getNames(); //извлечение имен
    void FillArray(std::string login, std::string name); //регистрация нового пользователя
    static int Get_records_in_file(const std::string name_file);
    void getListUsers_from_file(); //функция извлечения списка пользователей из файла
                                                  //для вставки в сообщения
    void DeleteEmptyLines(std::string file); //Удаление пустых строк из файла словаря
    friend std::ostream& operator<< (std::ostream& out, const User& user);
    friend std::istream& operator>> (std::istream& in, User& user);
    ~User() {};
};
