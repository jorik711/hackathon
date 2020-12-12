#include <iostream>
#include <string>
#include <map>

using namespace std;
int main()
{
    setlocale(LC_ALL, "Rus");
    string Name_1 = "a", Name_2 = "b", Name_3 = "c", Parole_1 = "a1", Parole_2 = "a2", Parole_3 = "a3"; //добавлены в качестве примера
    map <string, string> mapUsers;      //соответствие имени и пароля
    map <string, string>::iterator it;  //в которое будет добавляться соответственно имя и пароль юзера при создании нового объекта User
                                        //и через которе будет проверяться имя и пароль на входе
    mapUsers[Name_1] = Parole_1;
    mapUsers[Name_2] = Parole_2;
    mapUsers[Name_3] = Parole_3;


    bool exit = false;
    while (exit == false)
    {
        string option;
        cout << "Начало::Добро пожаловать в чат!!" << endl;
        cout << "Выберете опцию: зарегистрироваться - registr, войти - enter, выйти из чата - exit " << endl;
        cin >> option;
        if (option == "registr")
        {
            cout << "Введите имя" << endl;
            string Name;
            cin >> Name;
            cout << "Введите ник" << endl;
            string Nick;
            cin >> Nick;
            cout << "Введите пароль" << endl;
            string Parole;
            cin >> Parole;
            mapUsers.insert(pair<string, string>(Name, Parole));//находится здесь для отладки
            /*Chat_1.createAccount(Name, Nick, Parole)
            {
                this->setName(Name);
                this->setNick(Nick);
                this->setParole(Parole);

                mapUsers.insert(pair<string, string>(Name, Parole));
            }*/
        }
        else if (option == "enter")
        {
            cout << "Введите имя" << endl;
            string Name;
            cin >> Name;
            
            if (mapUsers.count(Name) > 0)
            {
                cout << "Введите пароль" << endl;
                string Parole;
                cin >> Parole;
                map <string, string>::iterator it = mapUsers.find(Name);
                if (it->second == Parole)
                {
                    cout << "Добро пожаловать в чат" << endl;
                }
                else
                {
                    cout << "Неправильно введет пароль" << endl;
                }
            }
            else
            {
                cout << "Нет такого имени" << endl;
            }
        }
        else if (option == "exit")
        {
            exit = true;
        }
    }


    return 0;
}

