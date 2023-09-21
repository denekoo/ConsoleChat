#pragma once
#include <string>
#include<iostream>



class Message 
{
private:
	// реквизиты отправаителя:
	int m_authorID;
	std::string m_messageAuthor; 

	//тело сообщения:
	std::string m_message;


public:
	Message(int authorID, std::string messageAuthor, std::string message) :
		m_authorID(authorID), m_messageAuthor(messageAuthor), m_message(message)
	{
	}

	Message( std::string messageAuthor, std::string message) :
		 m_messageAuthor(messageAuthor), m_message(message)
	{
	}

	Message( std:: string author)
	{
		m_messageAuthor = author;
	}

	void writeMessage()
	{
		std::cin >> m_message;
	}

	void writeMessage(std::string messageAuthor)
	{
		m_messageAuthor = messageAuthor;
		std::cin >> m_message;

	}

	bool showMessage() 
	{
		std::cout << "\t\t\t\t"  <<"User " << m_messageAuthor << " send to chat:\n";
		std::cout << "\t\t\t\t"  << m_message << std::endl;
		std::cout << "\t\t\t\t"  << "---------" << std::endl;
		
		if (m_message == "**") // Обеспечивает условие для выхода из чата
		{
			return false;
		}
		else return true;
	}
};