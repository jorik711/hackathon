#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class User
{
public:
	// �����������
	User();
	User(string name, string login, string const password);
	void blockUser(std::vector <User> & alluser);

	// �������
	string getUserName() const;
	string getLogin() const;
	string getPassword() const;
	vector <User> getUserBlacklist();
	int getUserBLsize();

	// �������
	void setUserName(char* value);
	void setLogin(char* value);
	void setPassword(char* value);
	~User();

private:
	vector <User> _blacklist;
	string Username;
	string Login;
	string Password;

};

