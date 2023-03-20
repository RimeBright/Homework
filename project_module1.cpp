#include "project_module1.h"
#include <iostream>

using namespace std;

bool User::registartion(string login, string psw)
{
	// all - рассылка на всех
	if (login == "all")
	{
		cout << "Ник all нельзя занимать" << endl;
		return true;
	}

	if ((login.empty()) || (psw.empty()))
	{
		cout << "ОШИБКА! Логин или пароль остались пустыми!" << endl;
		return true;
	}

	if (this->check_registration(login, psw) == 0) this->add_user(login, psw);

	cout << "Успешная авторизация под пользователем: " << login << endl;
	this->usr_login = login;
	this->usr_psw = psw;

	return false;
}

void User::add_user(string login, string psw)
{
	cout << "Ваш акккаунт не значился в числе зарегестриванных. Автоматическая регистрация..." << endl;
	this->users[this->active_num_users] = login + '@' + psw;
	this->active_num_users++;
}

int User::check_registration(string login, string psw)
{
	for (int i = 0; i < this->active_num_users; i++)
	{
		if ((this->users[i].substr(0, this->users[i].find('@')) == login) && (this->users[i].substr(this->users[i].find('@')+1) != psw)) return 2;
		else if (this->users[i] == login + '@' + psw) return 1;
	}
	return 0;
}

void User::send_message(string usr, string mes)
{
	if ((usr.empty()) || (mes.empty()))
	{
		cout << "ОШИБКА! Получатель или сообщение остались пустыми!" << endl;
		return;
	}

	if ((this->check_registration(usr, "") == 2) || (usr == "all"))
	{
		this->messages[this->sent_num_messages] = usr + " " + this->usr_login + ": " + mes;
		this->sent_num_messages++;

		cout << "Сообщение было успешно отправлено пользователю " << usr << endl;
	}
	else
	{
		cout << "ОШИБКА! Пользователю " << usr << " невозможно отправить сообщение! Проверьте правильность написания ника." << endl;
	}
}

void User::read_message()
{
	string tmp;
	char break_char = ' ';
	bool have_mess = false;

	for (int i = 0; i < this->sent_num_messages; i++)
	{
		tmp = messages[i].substr(0, this->messages[i].find(break_char));

		// проверка получателя сообщения
		if ((tmp == this->usr_login) || (tmp == "all"))
		{
			cout << messages[i].substr(tmp.length()+1) << endl;
			have_mess = true;
		}
	}

	if (not have_mess) cout << "Для вас ещё нет сообщений! Пообщайтесь в чате, чтобы их получить!" << endl;
}

void User::change_user(string login, string psw)
{
	// all - рассылка на всех
	if (login == "all")
	{
		cout << "Ник all нельзя занимать" << endl;
		return;
	}
	
	if ((login.empty()) || (psw.empty()))
	{
		cout << "ОШИБКА! Логин или пароль остались пустыми!" << endl;
		return;
	}

	// Если пользователь не зарегестрированн 
	if (this->check_registration(login, psw) == 0)  this->add_user(login, psw);

	// Если совпадает только ник
	else if (this->check_registration(login, psw) == 2)
	{
		cout << "Неверный пароль для пользователя: " << this->usr_login << endl;
		return;
	}

	
	cout << "Успешная смена пользователя: " << this->usr_login << " -> " << login << endl;
	this->usr_login = login;
	this->usr_psw = psw;

}

User::~User()
{
	cout << "Выход из чата..." << endl;
	delete[] this->messages;
	delete[] this->users;
}