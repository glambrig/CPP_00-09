// #include "PmergeMe.hpp"

// PmergeMe::PmergeMe()
// {

// }

// PmergeMe::PmergeMe(char **av)
// {
// 	for (int i = 1; av[i]; i++)
// 	{
// 		std::string s = av[i];
// 		if (!isNum(s))
// 			throw ("Error: Non-number value.");
// 		int n = atoi(av[i]);
// 		if (n < 0)
// 			throw ("Error: Negative number.");
// 	}
// 	makeVector(av);
// 	makeList(av);
// 	printUnsorted();
// }

// PmergeMe::PmergeMe(const PmergeMe& copy)
// {
// 	if (this != &copy)
// 	{
// 		this->_n = copy._n;
//         this->_v = copy._v;
//         this->_l = copy._l;
// 	}
// }

// PmergeMe& PmergeMe::operator=(const PmergeMe& rhs)
// {
// 	if (this != &rhs)
// 	{
// 		this->_n = rhs._n;
//         this->_v = rhs._v;
//         this->_l = rhs._l;
// 	}
// 	return (*this);
// }

// PmergeMe::~PmergeMe()
// {

// }

// void	PmergeMe::printUnsorted(void)
// {
// 	std::cout << "Before: " << std::endl;
// 	for (size_t i = 0; i < _v.size(); i++)
// 	{
// 		std::cout << _v[i] << " ";
// 	}
// 	std::cout << std::endl;
// }

// void	PmergeMe::printVector(void)
// {
// 	std::cout << "vector: " <<std::endl;
// 	for (std::vector<size_t>::const_iterator it = _v.begin(); it != _v.end(); it++)
// 	{
// 		std::cout << *it << " ";
// 	}
// 	std::cout << std::endl;
// }

// void	PmergeMe::printList(void)
// {
// 	std::cout << "list: " <<std::endl;
// 	for (std::list<size_t>::const_iterator it = _l.begin(); it != _l.end(); it++)
// 	{
// 		std::cout << *it << " ";
// 	}
// 	std::cout << std::endl;
// }

// void	PmergeMe::makeVector(char **av)
// {
// 	int len = 1;

// 	try
// 	{
// 		_v.reserve(3000);
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << e.what() << '\n';
// 	}
// 	while (av[len])
// 		len++;
// 	this->_n = len;
// 	for (len--; len > 0; len--)
// 		_v.insert(_v.begin(), atoi(av[len]));
// 	vectorSort(this->_v);
// 	// printVector();//remove later
// }

// void	PmergeMe::makeList(char **av)
// {
// 	int len = this->_n;

// 	while (av[len])
// 		len++;
// 	for (len--; len > 0; len--)
// 		_l.insert(_l.begin(), atoi(av[len]));
// 	// printList();//remove later
// }

// bool PmergeMe::isSorted(std::vector<size_t> &v)
// {
// 	for (size_t i = 1; i < v.size(); i++)
// 	{
// 		if (v[i] < v[i - 1])
// 			return false;
// 	}
// 	return true;
// }

// void	PmergeMe::vectorSort(std::vector<size_t> &v)
// {
// 	if (v.size() <= 1)
// 		return ;
// 	std::vector<std::pair<size_t, size_t> >	vPair;
// 	std::vector<size_t>						smallHalf;
// 	std::vector<size_t>						bigHalf;

// 	//	1. make pairs
// 	for (size_t i = 0; i < this->_n; i += 2)
// 	{
// 		//insert the numbers two by two such that vPair[0].first == n1, vPair[0].second == n2
// 		std::pair<size_t, size_t> p;
// 		p.first = v[i];
// 		if (i + 1 < this->_n - 1)
// 			p.second = v[i + 1];
// 		else
// 			p.second = v[i];	//use a duplicate number if _n % 2 == 0
// 		vPair.push_back(p);
// 	}
// 	//	2. perform vPair.size() comparisons, one per pair
// 	for (size_t i = 0; i < vPair.size(); i++)
// 	{
// 		if (vPair[i].first > vPair[i].second)
// 		{
// 			bigHalf.push_back(vPair[i].first);
// 			smallHalf.push_back(vPair[i].second);
// 		}
// 		else
// 		{
// 			smallHalf.push_back(vPair[i].first);
// 			bigHalf.push_back(vPair[i].second);	
// 		}
// 	}
// 	//	3. If the largest half isn't sorted already, recursive call to vectorSort()
// 	if (!isSorted(bigHalf))
// 		vectorSort(bigHalf);
// 	insertSmallIntoBig(smallHalf, bigHalf);
// 	v = bigHalf;
// 	printVector();
// }

// void	PmergeMe::insertSmallIntoBig(std::vector<size_t> &small, std::vector<size_t> &big)
// {
// 	//binary search and insertion
// 	for (std::vector<size_t>::iterator it = small.begin(); it != small.end(); it++)
// 	{
// 		size_t val = *it;
// 		std::vector<size_t>::iterator pos = std::lower_bound(big.begin(), big.end(), val);
// 		big.insert(pos, val);
// 	}
// }

// void	PmergeMe::listSort(void)
// {

// }


#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <utility> // for std::pair
#include <stdexcept> // for std::exception

class PmergeMe {
public:
    PmergeMe();
    PmergeMe(char **av);
    PmergeMe(const PmergeMe& copy);
    PmergeMe& operator=(const PmergeMe& rhs);
    ~PmergeMe();

    void printUnsorted(void);
    void printVector(void);
    void printList(void);
    void makeVector(char **av);
    void makeList(char **av);
    void vectorSort(std::vector<size_t> &v);
    void insertSmallIntoBig(std::vector<size_t> &smallHalf, std::vector<size_t> &bigHalf);

private:
    bool isNum(const std::string& s);
    bool isSorted(const std::vector<size_t> &v);
    void listSort(void);

    size_t _n;
    std::vector<size_t> _v;
    std::list<size_t> _l;
};

PmergeMe::PmergeMe() : _n(0) {}

PmergeMe::PmergeMe(char **av) {
    for (int i = 1; av[i]; i++) {
        std::string s = av[i];
        if (!isNum(s))
            throw std::invalid_argument("Error: Non-number value.");
        int n = atoi(av[i]);
        if (n < 0)
            throw std::invalid_argument("Error: Negative number.");
    }
    makeVector(av);
    makeList(av);
}

PmergeMe::PmergeMe(const PmergeMe& copy) {
    if (this != &copy) {
        this->_n = copy._n;
        this->_v = copy._v;
        this->_l = copy._l;
    }
}

PmergeMe& PmergeMe::operator=(const PmergeMe& rhs) {
    if (this != &rhs) {
        this->_n = rhs._n;
        this->_v = rhs._v;
        this->_l = rhs._l;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::printUnsorted(void) {
    std::cout << "Before: " << std::endl;
    for (size_t i = 0; i < _v.size(); i++) {
        std::cout << _v[i] << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::printVector(void) {
    std::cout << "vector: " << std::endl;
    for (std::vector<size_t>::const_iterator it = _v.begin(); it != _v.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::printList(void) {
    std::cout << "list: " << std::endl;
    for (std::list<size_t>::const_iterator it = _l.begin(); it != _l.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::makeVector(char **av) {
    int len = 1;

    try {
        _v.reserve(3000);
    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    while (av[len])
        len++;
    this->_n = len;
    for (len--; len > 0; len--)
	{
        _v.insert(_v.begin(), atoi(av[len]));
	}
	printUnsorted();
    vectorSort(this->_v);
	std::cout << "AFTER: " << std::endl;
    for (size_t i = 0; i < _v.size(); i++) {
        std::cout << _v[i] << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::makeList(char **av) {
    int len = this->_n;

    while (av[len])
        len++;
    for (len--; len > 0; len--)
        _l.insert(_l.begin(), atoi(av[len]));
}

bool PmergeMe::isNum(const std::string& s) {
    for (size_t i = 0; i < s.size(); ++i) {
        if (!isdigit(s[i]))
            return false;
    }
    return true;
}

bool PmergeMe::isSorted(const std::vector<size_t> &v) {
    for (size_t i = 1; i < v.size(); i++) {
        if (v[i] < v[i - 1])
            return false;
    }
    return true;
}

void PmergeMe::vectorSort(std::vector<size_t> &v) {
    if (v.size() <= 1)
        return;

    std::vector<std::pair<size_t, size_t> > vPair;
    std::vector<size_t> smallHalf;
    std::vector<size_t> bigHalf;

    // 1. make pairs
    for (size_t i = 0; i < v.size(); i += 2) {
        std::pair<size_t, size_t> p;
        p.first = v[i];
        if (i + 1 < v.size())
            p.second = v[i + 1];
        else
            p.second = v[i];  // use a duplicate number if _n is odd
        vPair.push_back(p);
    }

    // 2. perform vPair.size() comparisons, one per pair
    for (size_t i = 0; i < vPair.size(); i++) {
        if (vPair[i].first > vPair[i].second) {
            bigHalf.push_back(vPair[i].first);
            smallHalf.push_back(vPair[i].second);
        } else {
            smallHalf.push_back(vPair[i].first);
            bigHalf.push_back(vPair[i].second);
        }
    }

    // 3. If the largest half isn't sorted already, recursive call to vectorSort()
    if (!isSorted(bigHalf)) {
        vectorSort(bigHalf);
    }

    insertSmallIntoBig(smallHalf, bigHalf);

    v = bigHalf;
}

void PmergeMe::insertSmallIntoBig(std::vector<size_t> &smallHalf, std::vector<size_t> &bigHalf) {
    // binary search and insertion
    for (std::vector<size_t>::iterator it = smallHalf.begin(); it != smallHalf.end(); ++it) {
        size_t val = *it;
        std::vector<size_t>::iterator pos = std::lower_bound(bigHalf.begin(), bigHalf.end(), val);
        bigHalf.insert(pos, val);
    }
}

void PmergeMe::listSort(void) {
    // Not implemented
}
