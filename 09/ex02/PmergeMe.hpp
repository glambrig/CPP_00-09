#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>

bool	isNum(const std::string &s);

class PmergeMe
{
private:
	size_t				_n;	//how many numbers are passed as input
	std::vector<size_t>	_v;	//these are example containers, idk if i'm actually going to be using these particular ones
	std::list<size_t>	_l;	//these are example containers, idk if i'm actually going to be using these particular ones
public:
	PmergeMe();
	PmergeMe(char **av);
	PmergeMe(const PmergeMe& copy);
	PmergeMe& operator=(const PmergeMe& rhs);
	~PmergeMe();

	void	vectorSort(void);
	void	listSort(void);
	void	makeVector(char **av);
	void	makeList(char **av);
	void	printVector(void);
	void	printList(void);
};