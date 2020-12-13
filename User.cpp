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

void User::blockUser(std::vector <User> &alluser)
{
	std::cout << "+ Введите имя пользователя которого хотите заблокировать" << '\n';
	std::string name;
	std::cin >> name;
	int size = alluser.size();
	for (int c = 0; c < size; c++)
	{
		if (alluser[c].getUserName() == name)
		{

			this->_blacklist.push_back(alluser[c]);
		}
		else
			std::cout << "+ Данного пользователя не существует !" << endl;
	}
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

vector<User> User::getUserBlacklist()
{
	return _blacklist;
}

int User::getUserBLsize()
{
	int s = _blacklist.size();

	return s;
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

