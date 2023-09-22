#pragma once
#include <iostream>
#include "Chat.h"

//	// Что сделать:
//	// добавить пользователя -  в любое время? - сделано, добавление длины автоматическое в момент регистрации
//	// логин и пароль  - сделал  - осталось сделать проверку ввода для большей крутости - 
//	// смена пользователя - сделал
//	// отправка сообщений в чат - сделал
//	// отправка сообщений лично -  сделал
//	// вывод списка пользователей - сделал
//	// вывод всех сообщений пользователя - надо ли?

int main()
{
	Chat chat;
	std::cout << "Welcome to my chat!" << std::endl;
	std::cout << "Please enter your choose:		 \n " 
			  << "1 - Registrator;				 \n "
			  << "2 - Show all registred users;  \n "
			  << "3 - Private chat for 2 users   \n "
			  << "4 - Shared chat for all users  \n "
			  << "9 - Exit						 \n "
			  << std::endl;

	bool mainChat = true;
	while (mainChat == true)
	{
		switch (chat.numInput())
		{
		//			// вызов регистартора
		case 1:
			{
			chat.registrator();
			break;
			}

		//			// список участников чата
		case 2:
			{
			chat.showUserList();
			break;
			}

		//			// вызов личных сообщений
		case 3:
			{
			chat.privateChat();
			break;
			}

		//			// вызов общего чата
		case 4:
			{
			chat.chat();
			break;
			}
		//			// выход из программы
		case 9:
			{
			mainChat = false;
			break;
			}
		}
	}
	return 0;
	}