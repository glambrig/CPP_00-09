#include "Contact.hpp"

void	display_top_columns(void)
{
	std::cout << "     Index|"
		<< "First Name|"
		<< " Last Name|"
		<< "  Nickname|"
		<< std::endl;
}

void	shorten(std::string *s)
{
	(*s).resize(9);
	(*s).append(".");
}

std::string Contact::get_name(std::string which)
{
	if (which.compare("fname") == 0)
		return (_fname);
	else if (which.compare("lname") == 0)
		return (_lname);
	else if (which.compare("nname") == 0)
		return (_nname);
	return ("");
}

std::string Contact::get_num(void)
{
	return (_phone_number);
}

std::string	Contact::get_secret(void)
{
	return (_secret);
}

void	Contact::add_contact(void)
{
	std::cout << "Enter contact's first name: ";
	std::cin >> _fname;
	std::cout << "Enter contact's last name: ";
	std::cin >> _lname;
	std::cout << "Enter contact's nickname: ";
	std::cin >> _nname;
	std::cout << "Enter contact's darkest secret: ";
	std::cin >> _secret;
	std::cout << "Enter contact's phone number: ";
	std::cin >> _phone_number;
}

void	Contact::display(int index)
{
	if (_fname.empty() == true)
		return ;
	if (_fname.length() >= 9)
		shorten(&_fname);
	if (_lname.length() >= 9)
		shorten(&_lname);
	if (_nname.length() >= 9)
		shorten(&_nname);
	if (_secret.length() >= 9)
		shorten(&_secret);
	if (_phone_number.length() >= 9)
		shorten(&_phone_number);
	for (int i = 0; i < 9; i++)
		std::cout << ' ';
	if (index > 0)
		std::cout << index;
	for (int i = _fname.length(); i <= 10; i++)
		std::cout << ' ';
	std::cout << _fname;
	for (int i = _lname.length(); i <= 10; i++)
		std::cout << ' ';
	std::cout << _lname;
	for (int i = _nname.length(); i <= 10; i++)
		std::cout << ' ';
	std::cout << _nname << std::endl;
}
