#include <iostream>
#include "Chat.h"

Chat::Chat()
{

}

Chat::Chat(std::vector<User> user, std::vector<Message> message)
{
    _chatUsers = user;
    _message = message;
}
void Chat::runChat()
{
    User user = _actUser;
    Message message;
    bool newchat = true;
    while (newchat)
    {
        std::cout << "Выберите номер действия которое хотите выполнить" << '\n' <<
        "1. Написать сообщение" << '\n' <<
        "2. Прочитать сообщение" << '\n' <<
        "3. Посмотреть зарегистрированных пользователей" << '\n'<<
        "4. Выйти из аккаунта" << '\n';
        std::cout << "Выберите действие: " << '\n';
        int startchat = 0;
        std:cin >> startchat;
        switch (startchat)
        {
        case 1:
            message = message.sendMessage(user,_chatUsers,_message);
            _message.push_back(message);
            break;
        case 2:
            message.readMessage(user,_message);
            break;
        case 3:
            Chat::showUser(_chatUsers);
            break;
        case 4:
            std::cout << "Вы вышли из аккаунта!" << '\n';
            newchat = false;
            break;
        default:
            std::cout << "Такой команды нет!" << '\n';
            continue;
        }
    }
    
    
}
User Chat::registration()
{
    std::string name,login,password;
    std::cout << "Введите ваше имя: ";
    std::cin >> name;
    std::cout << "Введите логин: ";
    std::cin >> login;
    std::cout << "Придумайте пароль: ";
    std::cin >> password;
    User actuser = User(name,login,password);
    return actuser;
}
bool Chat::logInFunc(std::vector<User> alluser)
{   
    std::string login,password;
    std::cout << "Введите логин: ";
    std::cin >> login;
    std::cout << "Введите пароль: ";
    std::cin >> password;
    bool enter;
    int size = alluser.size();
    for(int c = 0; c < size; c++)
        {
            if(alluser[c].getLogin() == login && alluser[c].getPassword() == password)
            {
                this->_actUser = alluser[c];
                enter = true;
            }
            else
            {
                std::cout << "Неверный логин или пароль!" << '\n';
                enter = false;
            }
        }
    return enter;
}
void Chat::showUser(std::vector<User> &alluser)
{
    int size = alluser.size();
    for(int c = 0; c < size; c++)
    {
        std::cout << alluser[c].getUserName() << '\n';    
    }
} 
Chat::~Chat()
{

}