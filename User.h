#pragma once
#include <iostream>
#include <string>
#include <fstream>

class User
{
public:
	
	User();
	//User(string name, string login, string const password);
	User(std::string name, std::string login, std::string pass): Username(name), Login(login), Password(pass) {}
	
	friend std::fstream& operator >>(std::fstream& is, User& obj);
	friend std::ostream& operator <<(std::ostream& os, const User& obj);

	std::string getUserName() const;
	std::string getLogin() const;
	std::string getPassword() const;

	
	void setUserName(char* value);
	void setLogin(char* value);
	void setPassword(char* value);
	~User();

private:
	std::string Username;
	std::string Login;
	std::string Password;

};

