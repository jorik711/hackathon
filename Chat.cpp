#include <iostream>
#include "Chat.h"

Chat::Chat()
{

}
std::vector<User> Chat::getUserList()
{
    return this->_chatUsers;
}
std::vector<Message> Chat::getMessageList()
{
    return this->_message;
}
void Chat::setUserList(User user)
{
    this->_chatUsers.push_back(user);   
}
void Chat::setMessageList(Message message)
{
    this->_message.push_back(message);
}
void Chat::runChat()
{
    User user = _actUser;
    Message message;
    bool newchat = true;
    while (newchat)
    {

        std::cout << "----------------------------------------------------------" << '\n' <<
        "      Вы вoшли в чат как:" << _actUser.getLogin() << '\n' <<
        "| Выберите номер действия которое хотите выполнить        |" << '\n' <<
        "| 1. Написать сообщение                                   |" << '\n' <<
        "| 2. Прочитать сообщение                                  |" << '\n' <<
        "| 3. Посмотреть зарегистрированных пользователей          |"  << '\n'<<
        "| 4. Выйти из аккаунта                                    |" << '\n' <<
        "----------------------------------------------------------" << '\n';
        std::cout << std::endl;
        std::cout << "+ Выберите действие: ";
        int startchat = 0;
        std:cin >> startchat;
        switch (startchat)
        {
        case 1:
            message = message.sendMessage(user,_chatUsers,_message);
            Chat::setMessageList(message);
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
            std::cout << '\n' << "Такой команды нет!" << '\n' << '\n';
            continue;
        }
    }
    
    
}
void Chat::registration(std::vector<User> alluse)
{
    std::cout << "+ Введите данные для регистрации!" << '\n';
    std::string name,login,password;
    std::cout << "Введите ваше имя: ";
    std::cin >> name;
    std::cout << "Введите логин: ";
    std::cin >> login;
    bool enter = 1;
    int size = alluser.size();
    for (int c = 0; c < size; c++)
    {
        if (alluser[c].getLogin() == login)
        {
            cout << "Пользователь с таким логином уже существует" << endl;
            enter = 0;
            break;
        }
        else
        {
            enter = 1;
            continue;
        }
    }
    if (enter)
    std::cout << "Придумайте пароль: ";
    std::cin >> password;
    User actuser = User(name,login,password);
    Chat::setUserList(actuser); // добавление пользователя в массив
    std::cout << "+ Регистрация успешно завершена!" << '\n';
    std::cout << std::endl;
    
}
bool Chat::logInFunc(std::vector<User> alluser)
{   
    std::cout << "+ Введите данные для входа: " << '\n';
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
                break;
            }
    
        }
        std::cout << "+ Неверный логин или пароль!" << '\n';
        std::cout << std::endl;
    return enter;
}
void Chat::showUser(std::vector<User> &alluser)
{
    std::cout << "Список зарегистрированных пользователей: " << '\n';
    int size = alluser.size();
    for(int c = 0; c < size; c++)
    {
        std::cout << alluser[c].getUserName() << '\n';    
    }
} 
Chat::~Chat()
{

}
