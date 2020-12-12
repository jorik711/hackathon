#pragma once
#include <iostream>
#include <string>

using namespace std;

class User
{
public:
	// Конструктор
	
	User(string name, string login, string const password);

	// Геттеры
	string getUserName() const;
	string getLogin() const;
	string getPassword() const;

	// Сеттеры
	void setUserName(char* value);
	void setLogin(char* value);
	void setPassword(char* value);

private:
	string Username;
	string Login;
	string Password;

};

