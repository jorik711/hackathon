#ifndef CHAT_H
#define CHAT_H

#include <vector>
#include "Message.h"
#include "User.h"

class Chat
{
private:
    User _actUser;
    std::vector<User> _chatUsers; // вектор с пользователями
    std::vector<Message> _message; //вектор с сообщениями 

public:
    Chat();
    Chat(std::vector<User> user, std::vector<Message> message); // constructor
    void runChat();//  главное меню с выбором опции (написать сообщение,прочитать сообщение)
    User registration(); // регистрация
    bool logInFunc(std::vector<User> user); // вход в чат по логину и паролю
    void showUser(std::vector<User> &alluser); // показать зарегистрированных пользователей   
    ~Chat();
};

#endif /* __CHAT_H__ */
