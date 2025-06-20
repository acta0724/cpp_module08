#include <iostream>
#include <stack>
#include <list>
#include "MutantStack.hpp"

void test_mutant_stack() {
	std::cout << "===== Testing MutantStack =====" << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "Top: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "Size after pop: " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	std::cout << "\nIterating through MutantStack:" << std::endl;
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}
	
	std::cout << "\nTesting const iterators:" << std::endl;
	const MutantStack<int> const_mstack(mstack);
	MutantStack<int>::const_iterator cit = const_mstack.begin();
	MutantStack<int>::const_iterator cite = const_mstack.end();
	while (cit != cite) {
		std::cout << *cit << std::endl;
		++cit;
	}
	
	std::cout << "\nTesting reverse iterators:" << std::endl;
	MutantStack<int>::reverse_iterator rit = mstack.rbegin();
	MutantStack<int>::reverse_iterator rite = mstack.rend();
	while (rit != rite) {
		std::cout << *rit << std::endl;
		++rit;
	}

	std::cout << "\nTesting const reverse iterators:" << std::endl;
	MutantStack<int>::const_reverse_iterator crit = const_mstack.rbegin();
	MutantStack<int>::const_reverse_iterator crite = const_mstack.rend();
	while (crit != crite) {
		std::cout << *crit << std::endl;
		++crit;
	}
	
	std::cout << "\nTesting compatibility with std::stack" << std::endl;
	std::stack<int> s(mstack);
	std::cout << "Size of copied stack: " << s.size() << std::endl;
	std::cout << "Top of copied stack: " << s.top() << std::endl;
}

void test_list() {
	std::cout << "\n\n===== Testing std::list for comparison =====" << std::endl;
	std::list<int> lst;
	lst.push_back(5);
	lst.push_back(17);
	std::cout << "Back: " << lst.back() << std::endl;
	lst.pop_back();
	std::cout << "Size after pop: " << lst.size() << std::endl;
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);
	std::cout << "\nIterating through list:" << std::endl;
	std::list<int>::iterator it = lst.begin();
	std::list<int>::iterator ite = lst.end();
	++it;
	--it;
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}
}

int main() {
	test_mutant_stack();
	test_list();
	return 0;
}
