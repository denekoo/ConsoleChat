#include "Chat.h"



	Chat::Chat()
	{
		m_users.resize(m_usersCount+1);
	}

	Chat::~Chat()
	{
		
	}

	int  Chat::numInput()
	{
		int num;
		std::cin >> num;
		std::cin.clear();
		std::cin.ignore(10, '\n');
		if (num >= 0 && num <= 9)
			return num;
		else
		{
			std::cout << " Incorrect input! Enter nuber between 0 and 9.\n";
			numInput();
		}
	}
	int Chat::getUserCounter() { return m_usersCount; }

	void Chat::addUser()
	{
		++m_usersCount;
		m_users.resize( m_usersCount + 1 ); //+1 добавляем для корректной работы с m_usersCount 
	}

	void Chat::registrator()
	{
		int choice = 0;
		m_users[0].defaultUser("default", 0000);////
		std::cout << "Registrator." << std::endl;
		std::cout << "What do you want? \n";

		while (choice < 3)
		{
			std::cout << "Please choose the action: 1 - register, 2 - login, 3 - out of reg  \n" << std::endl;
		
			choice = numInput();
		
			switch (choice)
			{
			case 1:		// register
			{
					if (userRegister() == true)
					{
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
				userLogin();
				break;
			}
			case 3:		// out of reg
			{
				choice = 3;
				break;
			}
			
			default:
				std::cout << "Incorrect input!\n";
				//std::cin.clear();
				break;
			}
		}
		std::cout << "Done!\n";
	}

	bool Chat::checkUser(std::string userName) // Проверяем пользователя на совпадение имен. 
										 //  Если совпало-> проверку не прошел
	{
		for (int iii = 0; iii <= m_usersCount; ++iii)
		{
			if (m_users[iii].getUser() == userName)
				return false;
		}
		return true;
	}

	bool Chat::checkPassword(User user, int password) ////
	{
		if (user.getPassword() == password)
		{
			//user.setAuthStatus(true);
		
			std::cout << "Welcome to chat! \n";
			return true;
		}
		else
		{
			std::cout << "Incorrect password! \n";
			user.setActiveUser(false);
			return false;
		}
	}

	bool Chat::userRegister()
	{
		std::string userName;
		int password;
		bool regCorrect = true;

		while (regCorrect == false);
		{
			std::cout << "Enter your user name: \n";
			std::cin >> userName;

			if (checkUser(userName) == true)
			{
				addUser();
				m_users[m_usersCount].setName(userName);
				std::cout << "enter your password: \n";
				std::cin >> password;	// добавить проверку пароля
				m_users[m_usersCount].setPassword(password);
				
				regCorrect = true;
				bool isAuthorized = true;
				
				m_users[m_usersCount].setAuthStatus(true);		
			}
			else
			{
				std::cout << "A user with the same name already exists\n";
				regCorrect = false;
			}
			
		}
		return regCorrect;
	}

	bool Chat::userLogin()
	{
		std::cout << "User name: \n";
		std::string userName;
		std::cin >> userName;
		int tryCounter = 0; // ограничитель количества попыток логина
		while (tryCounter <= 3)
		{
			if (checkUser(userName) == false) // false - есть совпадение имен
			{

				for (int iii = 0; iii <= m_usersCount; ++iii)
				{
					if (m_users[iii].getUser() == userName)
					{
						std::cout << "Password: \n";
						int password;
						std::cin >> password;
						if (checkPassword(m_users[iii], password) == true)
						{
							m_users[iii].setActiveUser(true);
							return true;
						}
						else
						{
							std::cout << "Try again." << std::endl;
							userLogin();
							++tryCounter;
						}
					}
				}
				return false;
			}

			else
			{
				std::cout << "Incorrect username! Try again.\n";
				++tryCounter;
				return false;
			}
		}
	}
	
	void Chat::showUserList()
	{
		std::cout << "List of chat participants: \n";

		for (int index = 0; index <= m_usersCount; ++index)
		{
			std::cout << index << ". User " << m_users[index].getUser();

			if (m_users[index].getAuthorized() == true)
				std::cout << " is authorised ";
			else
				std::cout << " is not authorised ";

				if (m_users[index].getActiveUser() == true)
					std::cout << " - active.\n";
				else
					std::cout << " - not active\n";
		}
	}
	User Chat::selectUser()
	{
		std::cout << "Enter the number:\n";
		int userNumber = numInput();
		
		if (userNumber >= 0 && userNumber <= m_usersCount)
		{
			if(m_users[userNumber].getActiveUser() == true)
				return m_users[userNumber];
			else
			{
				std::cout << "Selected user is not active, select another user! \n";
				selectUser();
			}
		}
		else
		{
			std::cout << "Selected user is missing!\n Select another user or login.";
			 userLogin();
		}
	}

	bool Chat::chatMessage(User user)
	{
		Message message(user.getUser());
		m_messages.push_back(message);
		message.writeMessage();
		return message.showMessage();
	}

	void Chat::privateChat() //bool to end
	{
		std::cout << "Welcome to private chat!\n";
		std::cout << "Users list\n";

		showUserList();
		std::cout << "\nSelect first user from active users list: \n";
		User user1 = selectUser();

		std::cout << "Select second user from active users list: \n";
		User user2 = selectUser();
	
		std::cout << "Write your messages right now! :^)\n";
		std::cout << "Enter ** to leave the chat.\n";

		bool activeUser1 = true;
		bool activeUser2 = true;

		while (activeUser1 == true && activeUser2 == true )
		{
			 activeUser1 = chatMessage(user1);
			 activeUser2 = chatMessage(user2);
		}
	}


	void Chat::changeUser()
	{

	}

	void Chat::chat()
	{
		std::cout << "Welcome to  chat!\n";
		std::cout << "Users list\n";

		showUserList();

		std::cout << "\nSelect first user from active users list: \n";
		std::cout << "Write your messages right now! :^)\n";
		std::cout << "Enter ** to leave the chat.\n";

		bool activeUser1 = true;
	
		while (activeUser1 == true )
		{
		User user = selectUser();
		std::cout << "write your message:\n";
		activeUser1 = chatMessage(user);
		}
	}











