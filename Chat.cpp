#pragma once

#include <iostream>
#include "user.cpp"
#include "message.cpp"
//	//сервер чата
//	// добавить пользователя
//	// логин или пароль 
//	// смена пользователя
//	// отправка сообщений в чат
//	//



class Chat
{
private:
	
	User *ArrayUser;
	int m_arrayLenght;

public:

	int start()
	{
		std::cout << "Welcome to chat! \n Please enter the number for select option:";
		std::cout << "1 -  register \n 2 - login \n";
		
		int number;
		std::cin >> number;

		switch (number)
		{
		case 1:
		{
		
		}
		break;
		case 2:
		{
		
		}
		break;
		}

	}


	void addUser()
	{





	}
};


