#include "./PhoneBook.hpp"

void	print_specific(Contact contact)
{
	std::cout << "First Name: " << contact.get_name("fname") << std::endl;
	std::cout << "Last Name: " << contact.get_name("lname") << std::endl;
	std::cout << "NickName: " << contact.get_name("nname") << std::endl;
	std::cout << "Secret: " << contact.get_secret() << std::endl;
	std::cout << "Phone number: " << contact.get_num() << std::endl;
}

int	check_which(std::string s)
{
	if (s.compare("ADD") == 0)
		return (1);
	else if (s.compare("SEARCH") == 0)
		return (2);
	else if (s.compare("EXIT") == 0)
		return (3);
	return (0);
}

void	PhoneBook::AddContact(void)
{
	static int	i = 0;
		contacts[i++].add_contact();
	if (i == 8)
		i = 0;
}

void	PhoneBook::SearchContact(void)
{
	std::string s;
	
	display_top_columns();
	for (int i = 0; i < 8; i++)
	{
		contacts[i].display(i + 1);
	}
	std::cout << "Which contact would you like to see?" << std::endl;
	std::cin >> s;
	if (s.length() > 1 || (s[0] > '8' || s[0] < '1'))
	{
		std::cout << "Invalid index." << std::endl;
		return ;
	}
	else
		print_specific(contacts[(s[0] - '0') - 1]);
}

int	main(void)
{
	PhoneBook 	book;
	std::string str;

	while (1)
	{
		std::cout << "What would you like to do? (ADD, SEARCH, EXIT)" << std::endl;
		std::cin >> str;
		switch (check_which(str))
		{
			case 1:
				book.AddContact();
				break ;
			case 2:
				book.SearchContact();
				break ;
			case 3:
				return (0);
		}
	}
}
