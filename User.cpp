#include "User.h"
#include <fstream>

User::User() {}

// User::User(string name, string login, string const password)
// {
// 	Username = name;
// 	Login = login;
// 	Password = password;
// }

string User::getUserName() const {
	return Username;
}

string User::getLogin() const {
	return Login;
}

string User::getPassword() const {
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

fstream& operator >>(fstream& is, User& obj)
{
	is >> obj.Username;
	is >> obj.Login;
	is >> obj.Password;
	return is;
}

ostream& operator <<(ostream& os, const User& obj)
{
	os << obj.Username;
	os << ' ';
	os << obj.Login;
	os << ' ';
	os << obj.Password;
	return os;
}

User::~User() {}

