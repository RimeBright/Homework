#include <iostream>
#include "project_module1.h"
#include "Windows.h"

// для задания цвета консоли
HANDLE hConsole;

using namespace std;

void help()
{
	cout << "Команды чата\n1.send to_name text_message - отправка сообщения пользователю to_name. Если необходимо отправить всем, то to_name=all" << endl;
	cout << "2.read - чтение всех сообщений из чата, доступных вам.\n3.change new_usr new_psw - смена пользователя\n4.quit - выход из чата.\n5.help - вывод команд чата\n\n";
}

int main()
{
	setlocale(LC_ALL, "Russian");
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // для разноцветного вывода в консоль

	string input;
	bool first_start = true;

	// цвета для консоли
	int white = 7;
	int green = 2;
	int red = 4;
	int blue = 3;
	int orange = 6;

	string login, psw;

	User usr;

	while (true)
	{
		SetConsoleTextAttribute(hConsole, white);
		if (first_start)
		{
			cout << "Введите через пробел логин и пароль" << endl;
			getline(cin, input);

			login = input.substr(0, input.find(" "));
			psw = input.substr(login.length());
			cout << login << endl;
			SetConsoleTextAttribute(hConsole, blue);
			first_start = usr.registartion(login, psw);

			if (not first_start)
			{
				SetConsoleTextAttribute(hConsole, orange);
				help();
			}

		}
		else
		{
			cout << usr.usr_login << "> ";
			getline(cin, input);
			string command = input.substr(0, input.find(" "));

			if (command == "quit")
			{
				SetConsoleTextAttribute(hConsole, red);
				break;
			}
			else if (command == "help")
			{
				SetConsoleTextAttribute(hConsole, orange);
				help();
			}
			else if (command == "read")
			{
				SetConsoleTextAttribute(hConsole, green);
				usr.read_message();
			
			}
			else if (command == "change")
			{
				SetConsoleTextAttribute(hConsole, blue);
				input = input.substr(command.length()+1);
				login = input.substr(0, input.find(" "));
				psw = input.substr(login.length());
			
				usr.change_user(login, psw);
			}
			else if (command == "send")
			{
				SetConsoleTextAttribute(hConsole, green);
				input = input.substr(command.length() + 1);
				string to = input.substr(0, input.find(" "));
				string mess = input.substr(to.length());

				usr.send_message(to, mess);
			}
		}
	}
	
	return 0;
}