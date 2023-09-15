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

	//реквизиты получателя:
	int m_recipientID = 0;					//нет необходимости?
	std::string m_messageRecipient;		//нет необходимости?
	bool m_isPublic=false;
public:

	Message( std:: string author, std::string message, bool isPublic)
	{
		m_messageAuthor = author;
		m_message = message;
		m_isPublic = isPublic;
	}

	Message(int authorID, std::string messageAuthor, std::string message, int recipientID, std::string messageRecipient, bool isPublic) :
		m_authorID(authorID), m_messageAuthor(messageAuthor), m_message(message),
		m_recipientID(recipientID), m_messageRecipient(messageRecipient), m_isPublic(isPublic)
	{

	}
	Message(int authorID, std::string messageAuthor, std::string message) :
		m_authorID(authorID), m_messageAuthor(messageAuthor), m_message(message)
	{

	}

	void showMessage() //  автор и тело сообщения в параметр?
	{
		std::cout << m_messageAuthor << "send to chat:\n";
		std::cout << m_message << std::endl;
		std::cout << "---------" << std::endl;
	}
	

};