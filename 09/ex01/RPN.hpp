#pragma once

#include <iostream>
#include <stack>
#include <string>
#include <cstdlib>

#define ALLOWED_CHARS "+-/* 1234567890"
// operators, space, and nums

class RPN
{
	private:
		std::stack<double> _stack;
		double doOperation(char token);
		bool validInput(const std::string& expr);
		bool validOperand(char token);
	public:
		RPN();
		RPN(const RPN& src);
		RPN& operator=(const RPN& src);
		~RPN();
		void solveExpression(const std::string& expr);
};