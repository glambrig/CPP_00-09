#include "RPN.hpp"

rpn::rpn()
{

}

rpn::rpn(int ac, char *av)
{
	if (ac != 2)
	{
		std::cout << "Error: invalid number of arguments" << std::endl;
		return ;
	}
	addNums(av);
}

rpn::rpn(const rpn& copy)
{
	if (this != &copy)
		*this = copy;
}

rpn& rpn::operator=(const rpn& rhs)
{
	if (this != &rhs)
		*this = rhs;
	return (*this);
}

rpn::~rpn()
{

}

void	rpn::addNums(char *av)
{
	for (int i = 0; av[i]; i++)
	{
		if (av[i] != ' ')
			_stack.push_back(av[i]);
	}
}

/*Remember to change the error messages before git push*/
int	rpn::parse(void)
{
	std::string s;

	if (_stack.size() < 3)
	{
		std::cout << "rpn::parse::tooFewOperatorsError" << std::endl;
		return (1);
	}
	char op = _stack.back();
	_stack.pop_back();
	char b = _stack.back();
	_stack.pop_back();
	char a = _stack.back();
	_stack.pop_back();
	_stack.push_back(a);
	_stack.push_back(b);
	_stack.push_back(op);
	for (int i = 0; !_stack.empty(); i++)
	{
		s.append(1, _stack.back());
		_stack.pop_back();
	}
	for (int len = s.length(); len > 0;)
	{
		len--;
		if (!isNum(s[len]) && !isOperand(s[len]))
		{
			std::cout << "Error: invalid character." << std::endl;
	 		return (1);
		}
		if (isOperand(s[len]) && (len > 0 && isOperand(s[len - 1])))
		{
			std::cout << "rpn::parse::operatorFollowsOperator" << std::endl;
			return (1);
		}
	}
	if ((!isNum(a) || !isNum(b)) && !isOperand(op))
	{
		std::cout << "rpn::parse::invalidOrderError" << std::endl;
		return (1);
	}
	for (int i = s.length() - 1; s[i]; i--)
	{
		_stack.push_back(s[i]);
	}
	return (0);
}

int	rpn::calculate(void)
{
	char arr[3];
	
	if (parse() != 0)
		throw ("Parsing returned false.");
	while (!_stack.empty())
	{
		arr[0] = _stack.front();
		_stack.pop_front();
		arr[1] = _stack.front();
		_stack.pop_front();
		arr[2] = _stack.front();	//op
		_stack.pop_front();
		switch (arr[2])
		{
			case '+':
				_res.push_back((arr[0] - '0') + (arr[1] - '0'));
				break ;
			case '-':
				_res.push_back((arr[0] - '0') - (arr[1] - '0'));
				break ;
			case '*':
				_res.push_back((arr[0] - '0') * (arr[1] - '0'));
				break ;
			case '/':
				_res.push_back((arr[0] - '0') / (arr[1] - '0'));
				break ;
			default:
				return (_res.back());
		}
		_stack.push_front(_res.back() + '0');
	}
	return (_res.back());
}
