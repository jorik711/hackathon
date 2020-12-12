#include <iostream>
#include <string>
#include <map>
#include <fstream>

using namespace std;
int main()
{
    setlocale(LC_ALL, "Rus");
    string Name_1 = "a", Name_2 = "b", Name_3 = "c", Parole_1 = "a1", Parole_2 = "a2", Parole_3 = "a3";
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
            {   char ans;
                cout << "Введите пароль" << endl;
                string Parole;
                cin >> Parole;
                map <string, string>::iterator it = mapUsers.find(Name);
                if (it->second == Parole)
                {
                    cout << "Добро пожаловать в чат" << endl;
                    do
                    { 
                    cout << "Кому хотите отправить сообщение?" << endl;
                    
                    string a;
                    cin >> a;
                    string a1 = a + ".txt";//создает строку, которую легко можно вставить в A.open() для формирования имени файла
                    cout << "Какое сообщение хотите отправить?" << endl; 
                    string b;                                            
                    cin >> b; 
                   
                    getline(cin, a);
                
                    ofstream A(a);                          //создание объекта для перемещения сообщения в файл
                    A.open(a1.c_str());                     //открытие файла
                    A << "Отправлено thisUser:\n" << b;     //просто строка. вместо thisUser должно быть имя текущего пользователя
                    A.close();                              //закрытие файла


                    string line;                            //проверка и одновременная реализация
                    ifstream B(a);                          //изъятия у файла написанного в нем
                    B.open(a1.c_str());                     //аргумент "а" один и то же (для проверки)
                    if (B.is_open())                        //но в первом случае "а" - это то, кому мы отправляем
                    {                                       //во втором случае "а" - это сам нынешний юзер
                        while (getline(B, line))
                        {
                            cout << line << '\n';
                        }
                        B.close();
                    }
                  
                    cout << "Хотите отправить кому-нибудь сообщение? (y/n)" << endl;
                    
                    cin >> ans;
                    } while (ans == 'y');
                    cout << "Прочитите сообщения" << endl;
                   /*тут должен быть цикл для вывода всех сообщений, которые прислали юзеру.
                       для этого */

                    string a;
                    cin >> a;
                    string a1 = a + ".txt";

                    string line;                            //проверка и одновременная реализация
                    ifstream B(a);                          //изъятия у файла написанного в нем
                    B.open(a1.c_str());                     //аргумент "а" один и то же (для проверки)
                    if (B.is_open())                        //но в первом случае "а" - это то, кому мы отправляем
                    {                                       //во втором случае "а" - это сам нынешний юзер
                        while (getline(B, line))
                        {
                            cout << line << '\n';
                        }
                        B.close();
                    }

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

