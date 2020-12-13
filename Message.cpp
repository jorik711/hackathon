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
            cout << "От кого: " << allmess[c].getMuser() << '\n';
            cout << "Сообщение: " << allmess[c].getMessage() << '\n';
        }
        // else
        // {
        //     std::cout << "Для Вас нет новых сообщений!" << '\n';
        // }  
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
        }
    
    return mess;
}
Message::~Message()
{

}
