#pragma once
#include <string>

class User
{
	private:
		std::string usr_psw;

		int allowed_num_users = 10000;
		int allowed_num_messages = 32767;
		int active_num_users = 0;
		int sent_num_messages = 0;

		std::string* users = new std::string[allowed_num_users]; // пользователи хранятся в формате "user_name@user_password"
		std::string* messages = new std::string[allowed_num_messages]; // сообщения хранятся в формате "user_name(all) from_user_name: message_text"
	public:
		User() = default;
		~User();

		std::string usr_login;

		void send_message(std::string usr, std::string mes);
		void read_message();

		bool registartion(std::string login, std::string psw);
		int check_registration(std::string login, std::string psw);

		void add_user(std::string login, std::string psw);
		void change_user(std::string login, std::string psw);
};

