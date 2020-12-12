#ifndef CLASSMESSAGE_H
#define CLASSMESSAGE_H

#include <string>
#include "User.h"

class Message
{
private:
    std::string _senduser; // тот кому отправляется сообщение
    std::string _muser; // тот кто отправляет сообщение
    std::string _message; 
public:
    Message();
    Message sendMessage(User user, std::string message); //
    void readMessage(User user); // прочитать сообщение
    void setSenduser(User user);
    void setMuser(User user);
    ~Message();
};

#endif /* __CLASSMESSAGE_H__ */
