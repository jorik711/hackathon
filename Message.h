#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>
#include "User.h"
#include <vector>

class Message
{
private:
    std::string _senduser; // тот кому отправляется сообщение
    std::string _muser; // тот кто отправляет сообщение
    std::string _message; // отправляемое сообщение 
public:
    Message();
    void setSenduser(std::string name); // установить имя адресата
    std::string getSenduser(); // получить имя адресата
    std::string getMuser(); // получить имя отправителя
    void setMuser(User user); // // Установить имя отправителя
    void setMessage(std::string message); // написать сообщение
    std::string getMessage(); // получить сообщение

    friend fstream& operator >>(fstream& is, Message& obj);
	friend ostream& operator <<(ostream& os, const Message& obj);
    ~Message();
};

#endif /* __MESSAGE_H__ */
