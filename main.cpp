#include <iostream>
#include <string>
#include "Chat.h"
#include <vector>
#include "Message.h"


int main()
{
    std::vector<User> alluser;
    std::vector<Message> allmessage;
    Chat chat = Chat(alluser,allmessage);
    User user;
    bool start = true;
    while (start)
    {
        std::cout << "Добро пожаловать в чат!" << '\n' <<
        "Зарегистрируйтесь или войдите,усли у вас уже есть аккаунт!" << '\n' <<
        "Выберите номер действия которое хотите выполнить" << '\n' <<
        "1. Войти" << '\n' <<
        "2. Зарегистрироваться" << '\n' <<
        "3. Выйти из программы" << '\n';
        std::cout << "   Выберите действие: " << '\n';
        int work = 0;
        std:cin >> work;
        switch (work)
        {
        case 1:
            {
                if(chat.logInFunc(alluser))
                {
                    chat.runChat();
                    continue;
                }
            }
            break;
        case 2:
            {
                User user;
                user = chat.registration(); // регистрация пользователя
                alluser.push_back(user); // добавление пользователя в массив
            }
            break;
        case 3:
            std::cout << "Вы вышли из программы!" << '\n';
            start = false;
            break;
        default:
            std::cout << "Такой комманды нет!" << '\n';
            continue;
        }
    }
    
    return 0;
}