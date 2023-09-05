#pragma once
#include<string>
#include <iostream>


class User
{
private: 
	std::string m_userName;
	int m_password = 0000;
	bool isAuthorized = false;
	//User *array[];
public:

	User()		//	//default user; 
	{}

	User(std::string userName, int password): m_userName(userName), m_password(password)
	{}

	void showUser()
	{
		std::cout << "User " << m_userName << " joined to chat." << std::endl;
	}
	void defaultUser(std::string, int password)
	{
		m_userName = "default"; //
		m_password = 0000;
		isAuthorized = true;
	}


	/*User& operator [](int index)
	{
		return *array[index];
	}*/

	bool checkUser(User *array, int lenght, std::string userName) // проверяем пользователя на совпадение имен. 
																  //Если совпало-> проверку не прошел
	{
		for (int iii = 0; iii < lenght; ++iii)
		{
			if (array[iii].m_userName == userName)
				return false;
		}
		return true;
	}

	bool checkPassword(User user, int password) ////
	{
			if (user.m_password == password)
				return true;
		
		return false;
	}

	int setPassword() ////
	{


	}


	bool userRegister( User user[], int length) // передаем массив экземпляров класса для проверки пользователя
	{
		std::string userName;
		int password;
		bool regCorrect = true;
			while (regCorrect == false);
		{
			std::cout << "Enter your user name: \n";
			std::cin >> userName;

			if (checkUser(user,length, userName) == true)
			{
				m_userName = userName;
				std::cout << "enter your password: \n";
				std::cin >> password;	// добавить проверку пароля
				m_password = password;
				 regCorrect = true;
				isAuthorized = true;	
			}
			else
			{
				std::cout << "A user with the same name already exists\n";
				regCorrect = false;
			}
		}
				 return regCorrect;
	}

	bool userLogin(User *user, int length)
	{
		std::cout << "User name: \n";
		std::string userName;
		std::cin >> userName;
		if (checkUser(user, length, userName) == false)
		{
			std::cout << "Password: \n";
			int password;
			std::cin >> password;
			if (userName == user->m_userName && password == user->m_password)
			{
				std::cout << "Welcome to chat! \n";
				isAuthorized = true;
			}

			else
			{
				std::cout << "Incorrect password! \n";
				isAuthorized = false;
			}
		}
		else
			std::cout << "Incorrect username! Try again.\n";
				return isAuthorized;
	}

};