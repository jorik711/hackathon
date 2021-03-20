#include "Chat.h"

Chat::Chat() {}

void Chat::getUsersFromFile () {
    std::fstream user_file = std::fstream("users.txt", std::ios::in | std::ios::out);
    User obj;
    if (!user_file) {
		// Для создания файла используем параметр ios::trunc
        user_file = std::fstream("users.txt", std::ios::in | std::ios::out | std::ios::trunc);
    }
    // Чтобы считать данные из файла, надо установить позицию для чтения в начало файла
	user_file.seekg(0, std::ios_base::beg);
    if (user_file) {
        while (!user_file.eof()) {
		    user_file >> obj;
            setUserList(obj);                
        }
	}
	else {
		std::cout << "Could not open file users.txt !" << '\n';
	}
}   

void Chat::getMessageFromFile () {
    std::fstream message_file = std::fstream("messages.txt", std::ios::in | std::ios::out);
    Message obj;
    // Чтобы считать данные из файла, надо установить позицию для чтения в начало файла
	message_file.seekg(0, std::ios_base::beg);
    if (!message_file) {
		// Для создания файла используем параметр ios::trunc
        message_file = std::fstream("messages.txt", std::ios::in | std::ios::out | std::ios::trunc);
    }
    if (message_file) {
        while (!message_file.eof()) {
            // Считываем данные из файла
		    message_file >> obj;
            setMessageList(obj);
        }
	}
	else {
		std::cout << "Could not open file messages.txt !" << '\n';
	}
} 

std::vector<User> Chat::getUserList() {
    return this->_chatUsers;
}
std::vector<Message> Chat::getMessageList() {
    return this->_message;
}
void Chat::setUserList(User user) {
    this->_chatUsers.push_back(user);   
}
void Chat::setMessageList(Message message) {
    this->_message.push_back(message);
}
void Chat::runChat(Chat chat) {
    User user = _actUser;
    Message message;
    bool newchat = true;
    while (newchat)
    {
        std::cout << 
        "----------------------------------------------------------"  << std::endl <<
        "               Вы вoшли в чат как: " << _actUser.getLogin()  << std::endl <<
        "| Выберите номер действия которое хотите выполнить        |" << std::endl <<
        "| 1. Написать сообщение                                   |" << std::endl <<
        "| 2. Прочитать сообщение                                  |" << std::endl <<
        "| 3. Посмотреть зарегистрированных пользователей          |" << std::endl<<
        "| 4. Выйти из аккаунта                                    |" << std::endl <<
        "----------------------------------------------------------"  << std::endl;
        std::cout << std::endl;
        std::cout << "+ Выберите действие: ";
        int startchat = 0;
        std::cin >> startchat;
        switch (startchat)
        {
        case 1:
            chat.sendMessage(user,_chatUsers,_message);
            break;
        case 2:
            chat.readMessage(user,_message);
            break;
        case 3:
            Chat::showUser(_chatUsers);
            break;
        case 4:
            std::cout << "Вы вышли из аккаунта!" << std::endl;
            std::cout << std::endl;
            newchat = false;
            break;
        default:
            std::cout << std::endl << "Такой команды нет!" << std::endl << std::endl;
            continue;
        }
    }
}
void Chat::registration(std::vector<User> alluser) {
    std::fstream user_file = std::fstream("users.txt", std::ios::app | std::ios::in | std::ios::out );
	if (!user_file) { 
		// Для создания файла используем параметр ios::trunc
           user_file = std::fstream("users.txt", std::ios::in | std::ios::out | std::ios::trunc);
    }
    std::cout << "+ Введите данные для регистрации!" << std::endl;
    std::string name, login, password;
    std::cout << "Введите ваше имя: ";
    std::cin >> name;
    std::cout << "Введите логин: ";
    std::cin >> login;
    bool enter = 1;
    int size = alluser.size();
    for (int c = 0; c < size; c++) {
        if (alluser[c].getLogin() == login) {
            std::cout << "+ Пользователь с таким логином уже существует!" << std::endl;
            std::cout << std::endl;
            enter = 0;
            continue;
        }
    }
    if (enter) {
        std::cout << "Придумайте пароль: ";
        std::cin >> password;
        User actuser = User(name,login,password);      
        Chat::setUserList(actuser); // добавление пользователя в массив
        // запись User в файл  
        if (user_file) {
            // Запишем данные по в файл
		    user_file << actuser << std::endl;
	    }
	    else {
		    std::cout << "Файл не найден users.txt !" << std::endl;
	    }
        std::cout << "+ Регистрация успешно завершена!" << '\n';
        std::cout << std::endl;
    }
    
}
bool Chat::logInFunc(std::vector<User> alluser) {   
    std::cout << "+ Введите данные для входа: " << std::endl;
    std::string login,password;
    std::cout << "Введите логин: ";
    std::cin >> login;
    std::cout << "Введите пароль: ";
    std::cin >> password;
    bool enter = false;
    int size = alluser.size();
    for(int c = 0; c < size; c++) {
            if(alluser[c].getLogin() == login && alluser[c].getPassword() == password) {
                this->_actUser = alluser[c];
                enter = true;
                break;
            }
    
        }
        if (enter == false) {
            std::cout << "+ Неверный логин или пароль!" << std::endl;
            std::cout << std::endl;
        }
    return enter;
}
void Chat::showUser(std::vector<User> &alluser) {
    std::cout << "Список зарегистрированных пользователей: " << std::endl;
    int size = alluser.size();
    for(int c = 0; c < size; c++) {
        std::cout << alluser[c].getUserName() << std::endl;    
    }
}
void Chat::readMessage(User user,std::vector<Message> &allmess)
{
    int size = allmess.size();
    for(int c = 0; c < size; c++) {
        if(allmess[c].getSenduser() == user.getUserName() || allmess[c].getSenduser() == "all" ) {
            std::cout << "От кого: " << allmess[c].getMuser() << std::endl;
            std::cout << "Сообщение: " << allmess[c].getMessage() << std::endl;
        }
        // else
        // {
        //     std::cout << "Для Вас нет новых сообщений!" << std::endl;
        // }  
    }
    
}
void Chat::sendMessage(User user,std::vector<User> &alluser,std::vector<Message> &allmess) {
    std::fstream message_file = std::fstream("messages.txt", std::ios::app | std::ios::in | std::ios::out);
	    if (!message_file) { 
		// Для создания файла используем параметр ios::trunc
           message_file = std::fstream("messages.txt", std::ios::in | std::ios::out | std::ios::trunc);
        }
    Message mess;
    std::string name;
    std::cout << "Кому: ";
    std::cin >> name;
    mess.setMuser(user);
    int size = alluser.size();
    for(int c = 0; c < size; c++) {
            if(alluser[c].getUserName() == name) {
                mess.setSenduser(name);
                std::cout << "Oт кого: "<< mess.getMuser() << std::endl;
                
                std::string newmess;
                std::cout << "Введите сообщение: ";
                std::cin.ignore();
                getline(std::cin, newmess);
                std::cout << std::endl;
                mess.setMessage(newmess);
                //запись сообщения в файл 
                if (message_file) {
                    // Запишем данные по в файл
		            message_file << mess << std::endl;
	            }
	            else {
		            std::cout << "Файл не найден users.txt !" << std::endl;
	            }
                //запись сообщения в массив vector<Message>                
                allmess.push_back(mess);
            }
        }
        if (name == "all") {
            mess.setSenduser("all");
            std::cout << "Oт кого: "<< mess.getMuser() << std::endl;
            std::string newmess;
            std::cout << "Введите сообщение: ";
            std::cin.ignore();
            getline(std::cin, newmess);
            std::cout << std::endl;
            mess.setMessage(newmess);
            //запись сообщения в файл 
            if (message_file) {
                // Запишем данные по в файл
		        message_file << mess << std::endl;
	        }
	        else {
		        std::cout << "Файл не найден users.txt !" << std::endl;
	        }
            //запись сообщения в массив vector<Message>               
            allmess.push_back(mess);
        }
}
Chat::~Chat() {}
