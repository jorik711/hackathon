#include "User.h"

User::User() {}

std::string User::getUserName() const {
	return Username;
}

std::string User::getLogin() const {
	return Login;
}
std::string User::getPassword() const {
	return Password;
}

void User::setUserName(char* value) {
	Username = value;
}

void User::setLogin(char* value) {
	Login = value;
}

void User::setPassword(char* value) {
	Password = value;
}

std::fstream& operator >>(std::fstream& is, User& obj) {
	is >> obj.Username;
	is >> obj.Login;
	is >> obj.Password;
	return is;
}

std::ostream& operator <<(std::ostream& os, const User& obj) {
	os << obj.Username;
	os << ' ';
	os << obj.Login;
	os << ' ';
	os << obj.Password;
	return os;
}

User::~User() {}

