#include <iostream>
#include <string>
#include "Chat.h"
#include <vector>
#include "Message.h"


int main()
{
    Chat chat;
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
                if(chat.logInFunc(chat.getUserList()))
                {
                    chat.runChat();
                    continue;
                }
            }
            break;
        case 2:
            {
                User user;
                chat.registration(chat.getUserList()); // регистрация пользователя         
            }
            break;
        case 3:
            std::cout << '\n' << "Вы вышли из программы!" << '\n' << '\n';
            start = false;
            break;
        default:
            std::cout << '\n'<< "Такой комманды нет!" << '\n' << '\n';
            continue;
        }
    }
    
    return 0;
}