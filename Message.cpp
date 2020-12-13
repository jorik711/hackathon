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

void  Message::setSenduser(std::string name)
{
    this->_senduser = name;
}
void  Message::setMuser(User user)
{
    this->_muser = user.getUserName();
}

Message::~Message()
{

}
