#include <iostream>
#include <fstream>
#include <Windows.h>
#include "Hash.h"
#include "User.h"
#include "Message.h"
#include "Fs.h"
#include <filesystem> 


int main()
{
    setlocale(LC_ALL, "Rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    User u;
    Hash h;
    Message m;

    char xxxc;
    std::cout << "УСТАНОВИТЬ ПРАВА ДОСТУПА К ФАЙЛАМ ЗАПИСИ ДАННЫХ?"<< '\n';
    std::cout << "Вход в подпрограмму установки - 1, пропуск - 0" << '\n';
    std::cout << "____________________________________________________________________________________" << '\n';
    ag:
    std::cout << "Введите код операции: ";
    std::cin >> xxxc;
    if (xxxc != '1' && xxxc != '0')
    {
        std::cout << "Неверный ввод команды! Повторите: " << '\n';
        goto ag;
    }
    if(xxxc == '1')
    {
        Settings();
    }
    std::cout << '\n';

    char x = '1';
    std::cout << "ВНИМАНИЕ!  ЕСЛИ ВЫ ВХОДИТЕ В ЧАТ ВПЕРВЫЕ, ПРОЙДИТЕ РЕГИСТРАЦИЮ, ДЛЯ ЧЕГО НАЖМИТЕ  0." << '\n';
    std::cout << "      ЕСЛИ ВЫ - ЗАРЕГИСТРИРОВАННЫЙ ПОЛЬЗОВАТЕЛЬ, ДЛЯ ПРОДОЛЖЕНИЯ НАЖМИТЕ  1." << '\n';
    std::cout << "____________________________________________________________________________________" << '\n';
    again:
    std::cout << "Введите код операции: ";
    std::cin >> x;
    if (x != '1' && x != '0')
    {
        std::cout << "Неверный ввод команды! Повторите: " << '\n';
        goto again;
    }

    while (x == '0')
    {
        std::string login;
        std::string password;
        std::string name;

        again2:
        std::cout << " Введите пароль из восьми символов: ";
        std::cin >> password;
        if (password.size() != 8)
        {
            std::cout << " Неверное число символов. Введите повторно: " << '\n';
            goto again2;
        }
        rex:
        std::cout << " Введите логин из четырех символов: ";
        std::cin >> login;
        if (login.size() != 4)
        {
            std::cout << " Неверное число символов. Введите поворно: " << '\n';
            goto rex;
        }

        std::cout << "                       Введите имя: ";
        std::cin >> name;

        h.fillMap(password, login);
        u.FillArray(login, name);
        std::cout << '\n';

        std::cout << "Регистрация завершена успешно. Выполните повторный вход в программу" << '\n';
        exit(0);
    }

    //ВХОД ПО ПАРОЛЮ
    int count{};
    do
    {
        h.extractMap();
        std::string password;
        std::cout << "Введите пароль: ";
        std::cin >> password;
        bool ssy = h.on_guard(password);
        if (ssy == true)
        {
            std::cout << '\n';
            std::cout << "ВХОД РАЗРЕШЕН!" << '\n';
            break;
        }
        else
        {
            ++count;
        }
    } while (count < 3);
    if (count >= 3)
    {
        std::cout << '\n';
        std::cout << " -----------------------------------------------------------------------" << '\n';
        std::cout << "|       Сделаны три неверных попытки. Программа прекращает работу.      |" << '\n';
        std::cout << "|              Войдите повторно или пройдите регистрацию.               |" << '\n';
        std::cout << " -----------------------------------------------------------------------" << '\n';
        exit(0);
    }

    bool reflex{ true };
    bool repeat{ true };
    while (true)
    {
        std::cout << "ПРИВЕТ! КАКУЮ ОПЕРАЦИЮ ВЫ ХОТИТЕ ВЫПОЛНИТЬ?" << '\n';
        std::cout << '\n';
        std::cout << "Просмотреть список пользователей ..................2;" << '\n';
        std::cout << "Написать сообщение ................................3;" << '\n';
        std::cout << "Прочитать сообщения................................4;" << '\n';

        int ax{};            //переменная переключателя switch
        std::cout << '\n';
        std::cout << "Введите код операции: ";
        std::cin >> ax;
        switch (ax)
        {
        case 2:
            u.getListUsers_from_file();
            break;
        case 3:
            while (true)
            {
                std::string logSend;
                std::string logRec;
                std::cout << "Введите логин отправителя: ";
                std::cin >> logSend;
                std::cout << " Введите логин получателя: ";
                std::cin >> logRec;
                m.createMessages(logSend, logRec);
                int z{};
                std::cout << "Написать другому пользователю? Да - нажмите '1', нет - нажмите '0'" << '\n';
                std::cin >> z;
                if (z == 1)
                {
                    repeat = true;
                }
                else
                {
                    repeat = false;
                    break;
                }
                system("cls");
            }
            break;
        case 4:
            std::string login;
            std::cout << "Введите ваш логин: ";
            std::cin >> login;
            std::cout << '\n';
            m.readPersonalMessages(login);
            break;
        }
        int z{};
        std::cout << '\n';
        std::cout << "Желаете выполнить еще одну операцию? Да - нажмите '1', нет - нажмите '0'" << '\n';
        std::cin >> z;
        if (z == 1)
        { reflex = true; }
        else
        {   reflex = false;
            break;  }
    }

    return 0;
}

