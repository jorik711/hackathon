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
void Chat::runChat(Chat chat)
{
    User user = _actUser;
    Message message;
    bool newchat = true;
    while (newchat)
    {

        std::cout << "----------------------------------------------------------" << '\n' <<
        "               Вы вoшли в чат как: " << _actUser.getLogin() << '\n' <<
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
            chat.sendMessage(user,_chatUsers,_message);
            break;
        case 2:
            chat.readMessage(user,_message);
            break;
        case 3:
            Chat::showUser(_chatUsers);
            break;
        case 4:
            std::cout << "Вы вышли из аккаунта!" << '\n';
            std::cout << std::endl;
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
    bool enter = false;
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
        if (enter == false)
        {
            std::cout << "+ Неверный логин или пароль!" << '\n';
            std::cout << std::endl;
        }
        
        
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
void  Chat::readMessage(User user,std::vector<Message> &allmess)
{
    int size = allmess.size();
    for(int c = 0; c < size; c++)
    {
        if(allmess[c].getSenduser() == user.getUserName() || allmess[c].getSenduser() == "all" )
        {
            cout << "От кого: " << allmess[c].getMuser() << '\n';
            cout << "Сообщение: " << allmess[c].getMessage() << '\n';
        }
        // else
        // {
        //     std::cout << "Для Вас нет новых сообщений!" << '\n';
        // }  
    }
    
}
void Chat::sendMessage(User user,std::vector<User> &alluser,std::vector<Message> &allmess)
{
    Message mess;
    std::string name;
    cout << "Кому: ";
    cin >> name;
    mess.setMuser(user);
    int size = alluser.size();
    for(int c = 0; c < size; c++)
        {
            if(alluser[c].getUserName() == name)
            {
                mess.setSenduser(name);
                std::cout << "Oт кого: "<< mess.getMuser() << '\n';
                cout << "Введите сообщение: ";
                std::string newmess;
                std::cin >> newmess;
                cout << '\n';
                mess.setMessage(newmess);
                allmess.push_back(mess);

            }
       
        }
        if (name == "all")
        {
            mess.setSenduser("all");
            std::cout << "Oт кого: "<< mess.getMuser() << '\n';
            cout << "Введите сообщение: ";
            std::string newmess;
            std::cin >> newmess;
            cout << '\n';
            mess.setMessage(newmess);
            allmess.push_back(mess);
        }
}
Chat::~Chat()
{

}