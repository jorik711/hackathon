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
    Chat(); // constructor
    std::vector<User> getUserList();
    std::vector<Message> getMessageList();
    void sendMessage(User user,std::vector<User> &alluser,std::vector<Message> &allmess); // отправить сообщение
    void readMessage(User user,std::vector<Message> &allmess); // прочитать сообщение
    void setUserList(User user);
    void setMessageList(Message message);
    void runChat(Chat chat);//  главное меню с выбором опции (написать сообщение,прочитать сообщение)
    void registration(std::vector<User> alluser); // регистрация
    bool logInFunc(std::vector<User> user); // вход в чат по логину и паролю
    void showUser(std::vector<User> &alluser); // показать зарегистрированных пользователей   
    ~Chat();
};

#endif /* __CHAT_H__ */
