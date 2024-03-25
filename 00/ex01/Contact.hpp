#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

class	Contact
{
private:
	std::string	_fname;
	std::string	_lname;
	std::string	_nname;
	std::string	_phone_number;
	std::string	_secret;
public:
	std::string get_name(std::string which);
	std::string get_num(void);
	std::string	get_secret(void);
	void		add_contact(void);
	void		display(int index);
};

void	display_top_columns_full(void);
void	display_top_columns(void);
void	shorten(std::string *s);
void	print_specific(Contact contact);

#endif
