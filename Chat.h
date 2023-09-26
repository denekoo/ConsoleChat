#pragma once

#include <iostream>
#include <vector>
#include <ios> //used to get stream size
#include <limits> //used to get numeric limits
#include "User.h"
#include "Message.h"

class Chat
{
private:
	std::vector <User> m_users;
	int m_usersCount = 0;
	std::vector <Message> m_messages;
	int m_messagesCount = 0;

public:
	Chat();
	~Chat();

	int numInput();
	int getUserCounter();
	void addUser();
	void registrator();
	bool checkUser(std::string userName);
	bool checkPassword(User user, int password);
	bool userRegister();
	bool userLogin();
	void showUserList();
	User selectUser();
	bool chatMessage(User user);
	void privateChat();
	void chat();
};











