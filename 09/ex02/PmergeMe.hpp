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


	bool	isSorted(std::vector<size_t> &v);
	void	insertSmallIntoBig(std::vector<size_t> &small, std::vector<size_t> &big);
	void	vectorSort(std::vector<size_t> &v);
	void	makeVector(char **av);
	void	printVector(void);

	void	listSort(void);
	void	makeList(char **av);
	void	printList(void);
	void	printUnsorted(void);
};