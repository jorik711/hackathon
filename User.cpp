#include "User.h"

User::User()
{

}
//�����������
User::User(string name, string login, string const password)
{
	Username = name;
	Login = login;
	Password = password;
}

//�������
string User::getUserName() const
{
	return Username;
}

string User::getLogin() const
{
	return Login;
}

string User::getPassword() const
{
	return Password;
}

//�������
void User::setUserName(char* value)
{
	Username = value;
}

void User::setLogin(char* value)
{
	Login = value;
}

void User::setPassword(char* value)
{
	Password = value;
}
User::~User()
{
	
}

