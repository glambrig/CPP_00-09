#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{

}

PmergeMe::PmergeMe(char **av)
{
	for (int i = 1; av[i]; i++)
	{
		std::string s = av[i];
		if (!isNum(s))
			throw ("Error: Non-number value.");
		int n = atoi(av[i]);
		if (n < 0)
			throw ("Error: Negative number.");
	}
	makeVector(av);
	makeList(av);
}

PmergeMe::PmergeMe(const PmergeMe& copy)
{
	if (this != &copy)
	{
		*this = copy;
	}
}

PmergeMe& PmergeMe::operator=(const PmergeMe& rhs)
{
	if (this != &rhs)
		*this = rhs;
	return (*this);
}

PmergeMe::~PmergeMe()
{

}

void	PmergeMe::printVector(void)
{
	std::cout << "vector: " <<std::endl;
	for (std::vector<size_t>::const_iterator it = _v.begin(); it != _v.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void	PmergeMe::printList(void)
{
	std::cout << "list: " <<std::endl;
	for (std::list<size_t>::const_iterator it = _l.begin(); it != _l.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void	PmergeMe::makeVector(char **av)
{
	int len = 1;

	try
	{
		_v.reserve(3000);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	while (av[len])
		len++;
	this->_n = len;
	for (len--; len > 0; len--)
		_v.insert(_v.begin(), atoi(av[len]));
	printVector();//remove later
}

void	PmergeMe::makeList(char **av)
{
	int len = this->_n;

	while (av[len])
		len++;
	for (len--; len > 0; len--)
		_l.insert(_l.begin(), atoi(av[len]));
	printList();//remove later
}

void	PmergeMe::vectorSort(void)
{
	std::vector<std::pair<size_t, size_t> >	vPair;

	//make pairs
	for (size_t i = 0; i < this->_n; i++)
	{
		//insert the numbers two by two such that vPair[0].first == n1, vPair[0].second == n2
		vPair[i].first = this->_v[i];
		if (_v[i + 1].empty())
		{
			vPair[i].second = this->_v[i];	//insert duplicate number if _n % 2 == 1
			break ;
		}
		vPair[i].second = this->_v[i + 1];
		i++;
	}
	
}

void	PmergeMe::listSort(void)
{

}
