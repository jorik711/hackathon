#pragma once
#include <iostream>
#include <string>

using namespace std;

class User
{
public:
	
	User();
	//User(string name, string login, string const password);
	User(string name, string login, string pass):Username(name), Login(login), Password(pass) {}
	
	friend fstream& operator >>(fstream& is, User& obj);
	friend ostream& operator <<(ostream& os, const User& obj);

	string getUserName() const;
	string getLogin() const;
	string getPassword() const;

	
	void setUserName(char* value);
	void setLogin(char* value);
	void setPassword(char* value);
	~User();

private:
	string Username;
	string Login;
	string Password;

};

