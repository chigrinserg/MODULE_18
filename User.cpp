#include <iostream>
#include <fstream>
#include "User.h"

User::User(std::string& log, std::string& name)
    : m_log{ log }, m_name{ name } {}

User us;                      //объ€вл€ем экземпл€р класса

void User::setUsers(std::string login, std::string name)
{
    m_log=login;
    m_name=name;
}
void User::getUsers() //вывод пользовател€ на консоль при регистрации
{
    std::cout << '\n';
    std::cout << "________________________________________________________________________________________" << '\n';
    std::cout << " Ћогин: " << m_log << '\n';
    std::cout << "   »м€: " << m_name << '\n';
    std::cout << "________________________________________________________________________________________" << '\n';
}

std::ostream& operator<< (std::ostream& out, const User& user)
{
    out << user.m_log << " " << user.m_name; // причем тип функции также ссылочный, и воз-вращает параметр out в качестве возвращаемого типа
    return out;
}
std::istream& operator>> (std::istream& in, User& user)
{
    in >> user.m_log;
    in >> user.m_name;
    return in;
}

void User::getListUsers() //просмотр пользователем списка контактов
{
    std::cout << m_log << " "<< m_name << '\n';
}

std::string User::getLogins()
{
    return m_log;
}

std::string User::getNames()
{
    return m_name;
}

void User::FillArray(std::string login, std::string name) //функци€ создани€ списка пользователей
{
    us.setUsers(login, name);
    list_of_users.push_back(us);
    for (int i = 0; i < (end(list_of_users) - begin(list_of_users)); ++i) //выводим созданный массив на консоль
    {
        list_of_users[i].getUsers();
    }
    std::ofstream out("ListOfUsers.txt", std::ios::app); //сохран€ем массив в текстовый файл
    for (int i = 0; i < (end(list_of_users) - begin(list_of_users)); ++i)
    {
        out << list_of_users[i] << '\n';
    }
    std::cout << '\n';
}

int User::Get_records_in_file(const std::string name_file) //ѕодсчет числа строк в файле списка пользователей                                                         */
{
    int count = 0;
    std::ifstream input_file("ListOfUsers.txt");
    std::string s;
    while (!input_file.eof())
    {
        getline(input_file, s);
        ++count;
    }
    input_file.close();
    return count;
}

void User::DeleteEmptyLines(std::string file) //”даление пустых строк из списка
{
    std::ifstream in(file);
    std::string line, text;
    while (std::getline(in, line))
        if (!(line.empty() || line.find_first_not_of(' ') == std::string::npos))
        {
            text += line + "\n";
        }
    in.close();
    std::ofstream out(file);
    out << text;
}

void User::getListUsers_from_file() //функци€ извлечени€ списка пользователей из файла
{
    std::cout << "—ѕ»—ќ  ѕќЋ№«ќ¬ј“≈Ћ≈…: " << '\n';
    std::cout << '\n';
    std::vector<User> list_of_users(User::Get_records_in_file("ListOfUsers.txt"));
    std::ifstream input_file("ListOfUsers.txt");
    for (int i = 0; i < (Get_records_in_file("ListOfUsers.txt")); ++i)
    {
        input_file >> list_of_users[i];
    }
    input_file.close();
    for (int i = 0; i < (Get_records_in_file("ListOfUsers.txt")) - 1; ++i)
    {
        list_of_users[i].getListUsers();
    }
}

