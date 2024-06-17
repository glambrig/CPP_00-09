#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(const RPN& src)
{
	(void)src;
}

RPN &RPN::operator=(const RPN& src)
{
	(void)src;
	return (*this);
}

RPN::~RPN()
{
}

void RPN::solveExpression(const std::string& expr)
{
	if (!RPN::validInput(expr))
	{
		std::cerr << "Error: invalid expression." << std::endl;
		return;
	}

	// push chars one by one into the stack until a operation is found
	// then pop the last two chars in the stack and perform the operation between them

	std::string token;
	for (size_t i = 0, len = expr.length(); i < len; i++)
	{
		token = expr[i];
		if (token[0] == ' ')
			continue;
		if (isdigit(token[0]))
			this->_stack.push(atof(token.c_str())); // convert string to double then push
		else
			this->_stack.push(RPN::doOperation(token[0])); // do operation then push
	}
	std::cout << this->_stack.top() << std::endl;
}

double RPN::doOperation(char token)
{
	double num1, num2;

	if (this->_stack.empty())
		throw std::runtime_error("Error: Invalid operation.");
	// récup le dernier élément de la _stack et le supprime
	num2 = this->_stack.top();
	this->_stack.pop();

	if (this->_stack.empty())
		throw std::runtime_error("Error: Invalid operation.");

	num1 = this->_stack.top();
	this->_stack.pop();

	switch (token)
	{
	case '+':
		return (num1 + num2);
		break;

	case '-':
		return (num1 - num2);
		break;

	case '*':
		return (num1 * num2);
		break;

	case '/':
		if (num2 == 0)
			throw std::runtime_error("Error: division by zero.");
		return (num1 / num2);
		break;

	default:
		throw std::runtime_error("Error: invalid operation token: " + std::string(1,token));
		break;
	}
}

bool RPN::validInput(const std::string& expr)
{
	for(size_t i = 0; i < expr.length(); i++)
	{
		if (!isdigit(expr[i]) && expr[i] != ' ' && !validOperand(expr[i]))
			return (false);
	}
	return (true);
}

bool RPN::validOperand(char token)
{
	if (token == '+' || token == '-' || token == '*' || token == '/')
		return (true);
	return(false);
}
