#pragma once

#include <iostream>
#include "User.cpp"
#include "Message.cpp"
#include "chat.cpp"

//	//сервер чата -нет
//	// добавить пользователя -  в любое время?
//	// логин и пароль  - сделал 
//	// смена пользователя - нет
//	// отправка сообщений в чат - нет
//	//

void registrator(User array[], const int& maxUsers)
{
	int choice = 0;
	int userCount = 1; // 0 - default user;

	array[0].defaultUser("default", 0000);
	std::cout << "Welcome to my chat!" << std::endl;
	std::cout << "What do you want? \n";

	while ((userCount > maxUsers) || (choice < 3))
	{
		std::cout << "Please choose the action: 1 - register, 2 - login, 3 - out of reg  \n" << std::endl;

		std::cin >> choice;
		switch (choice)
		{
		case 1:		// register
		{
			if (userCount > 0 && userCount <= maxUsers)
			{
				if (array[userCount].userRegister(array, maxUsers) == true)
				{
					++userCount;
					std::cout << "User registred sucsefully!" << std::endl;
				}
				else
				{
					std::cout << "User not register!" << std::endl;
				}
				break;
			}

		case 2:		//login
		{
			array[userCount].userLogin(array, maxUsers);
			break;
		}
		case 3:		// out of reg
		{
			choice = 3;
			break;
		}

		}
		default:
			break;
		}
	}
	std::cout << "Done!\n";
}


int main()
{
	const int maxUsers = 10;
	User array[maxUsers];

	//registrator(array, maxUsers);

	array[0].showUser();





	return 0;
}