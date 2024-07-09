#pragma once
#include <iostream>
#include <string>
#include <unordered_map>

class Hash
{
private:
    std::string m_login;
    std::string m_pass;
    std::unordered_map<std::string, std::string> list_of_passes; //хеш-таблица сохранения паролей и номеров пользователей

public:
    Hash() {};
    Hash(std::string login, std::string pass);
    std::unordered_map<std::string, std::string>::iterator it;

    bool on_guard(std::string password); //допуск по паролю
    void fillMap(std::string login, std::string password);   //функция заполнения хеш-таблицы
    void extractMap();                             //извлечение таблицы из файла
    int countPasses(const std::string name_file);  //подсчет числа строк в текстовом файле словаря
    std::string getpass(int n);                    //Извлечение из файла паролей для загрузки в хеш-таблицу
    std::string getLogin(int n);                              //Извлечение из файла личных номеров для загрузки в хеш-таблицу
    void print();
    ~Hash() {};
};
