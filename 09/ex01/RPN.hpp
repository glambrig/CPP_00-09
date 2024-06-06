#pragma once

#include <iostream>
#include <stack>
#include <cstdlib>

bool	isNum(char c);
bool	isOperand(char c);

class rpn
{
private:
	std::deque<char>	_stack;
	std::deque<int>		_res;
public:
	rpn();
	rpn(int ac, char *av);
	rpn(const rpn& copy);
	rpn& operator=(const rpn& rhs);
	~rpn();

	void	addNums(char *av);
	int		parse(void);
	int	calculate(void);
};