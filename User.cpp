#pragma once
#include<string>
#include <iostream>
#include <vector>

class User
{
private: 
	std::string m_userName;
	int m_password = 0000;
	bool m_isAuthorized = false;
	bool m_activeUser = false;
	
public:

	User()		//	//default user; 
	{}

	User(std::string userName, int password): m_userName(userName), m_password(password)
	{}
	
	void setName(std::string name) { m_userName = name;}
	void setPassword(int password) { m_password = password;}
	void setAuthStatus(bool auth)  { m_isAuthorized = auth;}
	void setActiveUser(bool active)	{ m_activeUser = active;}

	bool		 getActiveUser() { return m_activeUser;}
	std::string  getUser()		 { return m_userName;}
	bool		 getAuthorized() { return m_isAuthorized;}
	int			 getPassword()	 { return m_password;}
	
	void showUser()
	{
		std::cout << "User " << m_userName << " joined to chat." << std::endl;
	}
	void defaultUser(std::string, int password)
	{
		m_userName = "default"; //
		m_password = 0000;
		m_isAuthorized = true;
	}

	//int& operator [](int index)
	//{
	//	return User user[index];//
	//}

	//bool checkUser(std::vector<User> array, int lenght, std::string userName) // проверяем пользователя на совпадение имен. 
	//															  //Если совпало-> проверку не прошел
	//{
	//	for (int iii = 0; iii < lenght; ++iii)
	//	{
	//		if (array[iii].m_userName == userName)
	//			return false;
	//	}
	//	return true;
	//}

	



	

	

};