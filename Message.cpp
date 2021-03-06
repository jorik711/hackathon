#include <iostream>
#include <fstream>
#include "Message.h"
#include "User.h"

Message::Message() {}
 std::string Message::getSenduser()  {
     return this->_senduser;
 }
 std::string Message::getMuser() {
     return this->_muser;
 }

std::string Message::getMessage() {
    return this->_message;
}
void Message::setMessage(std::string message) {
    _message = message;
}

void  Message::setSenduser(std::string name) {
    this->_senduser = name;
}
void  Message::setMuser(User user) {
    this->_muser = user.getUserName();
}

std::fstream& operator >>(std::fstream& is, Message& obj) {
	is >> obj._senduser;
	is >> obj._muser;
	is >> obj._message;
	return is;
}

std::ostream& operator <<(std::ostream& os, const Message& obj) {
	os << obj._senduser;
	os << ' ';
	os << obj._muser;
	os << ' ';
	os << obj._message;
	return os;
}

Message::~Message() {}
