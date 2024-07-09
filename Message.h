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
    std::vector<Message> array; //������ ������ ���������
    void setData(std::string logSend, std::string logRec);//��������� ������ ������������ ���������
    void getData(); //��������� � ����� ��������� � ������ ������
    void createMessages(std::string logSend, std::string logRec); //�������� ������������ ���������
    static int countRecords(const std::string name_file); //������� ����� ����� � ��������� �����
    std::string getLoginSender(); //����������  ������� ������ �����������
    std::string getLoginReceiver(); //���������� ������� ������ ����������
    void readPersonalMessages(std::string log_in); //������ ������������ ���������
    friend std::ostream& operator<< (std::ostream& out, const Message& z);
    friend std::istream& operator>> (std::istream& in, Message& z);
    ~Message(){};
};
