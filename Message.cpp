#include <iostream>
#include "Message.h"
#include "User.h"

Message::Message()
{
    
}
 std::string Message::getSenduser()
 {
     return this->_senduser;
 }
 std::string Message::getMuser()
 {
     return this->_muser;
 }

std::string Message::getMessage()
{
    return this->_message;
}
void Message::setMessage(std::string message)
{
    _message = message;
}

void  Message::readMessage(User user,std::vector<Message> &allmess)
{
    int size = allmess.size();
    for(int c = 0; c < size; c++)
    {
        if(allmess[c].getSenduser() == user.getUserName() || allmess[c].getSenduser() == "all" )
        {
            cout << "Сообщение от: " << allmess[c]._muser << '\n';
            cout << allmess[c].getMessage() << '\n';
        }
        else
        {
            std::cout << "Для Вас нет новых сообщений!" << '\n';
        }
        
    }
    
}
void  Message::setSenduser(std::string name)
{
    this->_senduser = name;
}
void  Message::setMuser(User user)
{
    this->_muser = user.getUserName();
}
Message Message::sendMessage(User user,std::vector<User> &alluser,std::vector<Message> &allmess)
{
    Message mess;
    
    std::string name;
    cout << "Кому: " << '\n';
    cin >> name;
    int size = alluser.size();
    for(int c = 0; c < size; c++)
        {
            if(alluser[c].getUserName() == name || name == "all")
            {
                mess.setSenduser(name);
                break;
            }
            else
            {
                std::cout << "Такого пользователя не существует" << '\n';
            }
        }
    cout << "Oт кого: "<< user.getUserName() << '\n';
    std:cout << "Введите сообщение: " << '\n';
    std::string newmess;
    std::getline(std::cin,newmess);
    mess.setMessage(newmess);
    return mess;
}
Message::~Message()
{

}
