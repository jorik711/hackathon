#pragma once
#include <iostream>
#include <string>

using namespace std;

class User
{
public:
	// �����������
	User();
	User(string name, string login, string const password);

	// �������
	string getUserName() const;
	string getLogin() const;
	string getPassword() const;

	// �������
	void setUserName(char* value);
	void setLogin(char* value);
	void setPassword(char* value);

private:
	string Username;
	string Login;
	string Password;

};

