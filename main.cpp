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
        std::cout << "**************************************************************" << std::endl <<
        "*                 Добро пожаловать в чат!                    *"<< std::endl <<
        "* Зарегистрируйтесь или войдите,усли у вас уже есть аккаунт! *" << std::endl <<
        "* Выберите номер действия которое хотите выполнить:          *" << std::endl <<
        "* 1. Войти                                                   *" << std::endl <<
        "* 2. Зарегистрироваться                                      *" << std::endl <<
        "* 3. Выйти из программы                                      *" << std::endl <<
        "**************************************************************" << std::endl;
        std::cout << std::endl << "+ Выберите действие: ";
        int work = 0;
        std:cin >> work;
        std::cout << std::endl;
        switch (work)
        {
        case 1:
            {
                if(chat.logInFunc(chat.getUserList())) // вход в чат
                {
                    chat.runChat(chat); // меню чата
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
            std::cout << std::endl << "Вы вышли из программы!" << std::endl << std::endl;
            start = false;
            break;
        default:
            std::cout << std::endl<< "Такой комманды нет!" << std::endl << std::endl;
            continue;
        }
    }
    
    return 0;
}