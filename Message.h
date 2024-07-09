#pragma once
#include <iostream>
#include <string>
#include <vector>

class Message
{
    std::string m_loginSender;
    std::string m_loginReceiver;
    std::string m_text;

public:
    Message(){};
    Message(std::string loginSender, std::string loginReceiver, std::string text);
    std::vector<Message> array; //массив записи сообщений
    void setData(std::string logSend, std::string logRec);//установка данных персональных сообщений
    void getData(); //получение и вывод введенных в массив данных
    void createMessages(std::string logSend, std::string logRec); //создание персональных сообщений
    static int countRecords(const std::string name_file); //подсчет числа строк в текстовом файле
    std::string getLoginSender(); //извлечение  личного номера отправителя
    std::string getLoginReceiver(); //извлечение личного номера получателя
    void readPersonalMessages(std::string log_in); //чтение персональных сообщений
    friend std::ostream& operator<< (std::ostream& out, const Message& z);
    friend std::istream& operator>> (std::istream& in, Message& z);
    ~Message(){};
};
