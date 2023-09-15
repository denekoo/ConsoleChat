#pragma once
#include <string>
#include <iostream>


class Message
{
private:
	std::string m_author;
	std::string m_message;
	bool m_isPublic;

public:
	Message()
	{
		m_author ="default";
		m_message = "empty";
		m_isPublic = false;
	}

	Message(std::string author, std::string message, bool isPublic): m_author(author), m_message(message), m_isPublic(isPublic)
	{}



};
/*Chat(User *user, Message *message)
	{
		m_user = nullptr;
		m_userCount = 0;
		m_message = nullptr;
		m_messageCount = 0;
	}*/