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

public:

	Message(int authorID, std::string messageAuthor, std::string message, int recipientID, std::string messageRecipient) :
		m_authorID(authorID), m_messageAuthor(messageAuthor), m_message(message),
		m_recipientID(recipientID), m_messageRecipient(messageRecipient)
	{

	}
	Message(int authorID, std::string messageAuthor, std::string message) :
		m_authorID(authorID), m_messageAuthor(messageAuthor), m_message(message)
	{

	}

	void sendMessage() //  автор и тело сообщения в параметр?
	{
		std::cout << m_messageAuthor << "send to chat:\n";
		std::cout << m_message << std::endl;
		std::cout << "---------" << std::endl;
	}
	void writeMessage()
	{


		std::cin >> m_message; //проверить строку, а потом положить в m_message?

	}

};