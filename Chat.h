#ifndef CHAT_H
#define CHAT_H

#include <vector>
#include "Message.h"
#include "User.h"

class Chat
{
private:
    User* _actUser;
    std::vector<User*> _chatUsers; // вектор с пользователями
    std::vector<Message> _message; //вектор с сообщениями 

public:
    Chat(std::vector<User> user, std::vector<std::string> message); // constructor
    void runChat();// главное меню с выбором опции (регистраци, вход)
    User registration(); // регистрация
    bool logInFunc(User user); // вход в чат по логину и паролю
    void showUser(); // показать зарегистрированных пользователей   
    ~Chat();
};

#endif /* __CHAT_H__ */
