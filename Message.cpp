#include <iostream>
#include "Message.h"
#include <string>
#include <vector>
#include <fstream>

Message::Message(std::string loginSender, std::string loginReceiver, std::string text)
    : m_loginSender{ loginSender }, m_loginReceiver{ loginReceiver }, m_text{ text }{}

std::ostream& operator<< (std::ostream& out, const Message& z)
{
    out << z.m_loginSender << " " << z.m_loginReceiver << " " << " " << z.m_text;
    return out;
}

std::istream& operator>> (std::istream& in, Message& z)
{
    in >> z.m_loginSender;
    in >> z.m_loginReceiver;
    in >> z.m_text;
    return in;
}

void Message::setData(std::string logSend, std::string logRec)  //Установка данных сообщения
{
    m_loginSender = logSend;
    m_loginReceiver = logRec;
    std::cout << "                Сообщение: ";
    std::getline(std::cin >> std::ws, m_text); //обеспечивает ввод  текста с пробелами
    for (size_t i = static_cast<int>(m_text.find(' ')); i != -1; i = m_text.find(' ')) m_text.replace(i, 1, "_");
}

void Message::getData() //Получение данных сообщения
{
    std::cout << "     От кого: " << m_loginSender <<'\n';
    std::cout << "        Кому: " << m_loginReceiver << '\n';
    std::cout << "   СООБЩЕНИЕ: " << m_text << '\n';
}

Message message; //Объявление экземпляра класса для использования в функции создания и сохранения сообщений

std::string Message::getLoginSender() //извлечение номера отправителя
{
    return m_loginSender;
}

std::string Message::getLoginReceiver() //извлечение номера получателя
{
    return m_loginReceiver;
}

void Message::createMessages(std::string logSend, std::string logRec) //ФУНКЦИЯ СОЗДАНИЯ ЛИЧНЫХ СООБЩЕНИЙ
{
    int size{ 1 };
    std::vector<Message> array(size); //массив сохранения сообщений
    for (int i = 0; i < size; ++i)
    {
        array[i].setData(logSend, logRec);
    }
    for (int j = 0; j < size; ++j)
    {
        int a{};
        std::cout << "Еще одно сообщение? Да - 1, Нет - 0" << '\n';
        std::cin >> a;
        if (a == 1)
        {
            ++size;
            message.setData(logSend, logRec);
            array.push_back(message);
        }
        else
            break;
    }
    for (int i = 0; i < (end(array) - begin(array)); ++i)
    {
        array[i].getData();
    }

    std::ofstream out("Messages.txt", std::ios::app); //сохраняем массив в текстовый файл
    for (int i = 0; i < (end(array) - begin(array)); ++i)
    {
        out << array[i] << '\n';
    }
}

int Message::countRecords(const std::string name_file) // Подсчитываем число строк в файле
{
    int count = 0;
    std::ifstream input_file("Messages.txt");
    std::string s;
    while (!input_file.eof())
    {
        getline(input_file, s);
        ++count;
    }
    input_file.close();
    return count;
}

void Message::readPersonalMessages(std::string log_in) //функция чтения персональных сообщений
{
    std::vector<Message>array(Message::countRecords("Messages.txt"));
    std::ifstream input_file("Messages.txt", std::ios::in);
    for (int i = 0; i < (Message::countRecords("Messages.txt")); ++i)
    {
        input_file >> array[i];
    }
    input_file.close();
    bool send=false;
    for (int i = 0; i < (Message::countRecords("Messages.txt")) - 1; ++i)
    {
        /*-1 вводится для предотвращения вывода пустых сообщений, созданных конструктором по умолчанию
        при чтении последней пустой строки*/
        /*Нижеследующим условием предотвращается чтение пользователем не ему адресованных
        личных сообщений:*/
        if (log_in == array[i].getLoginSender() || log_in == array[i].getLoginReceiver())
        {
            array[i].getData();
            send = true;
        }
    }
    if (send == false)
    {
        std::cout << "У вас нет сообщений!" <<'\n';
    }
}

