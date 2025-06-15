#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main() {
	std::cout << "=== Non-const container test ===" << std::endl;
	std::vector<int> vec;
	for (int i = 0; i < 10; i++)
		vec.push_back(i);
	try {
		std::vector<int>::iterator it = easyfind(vec, 5);
		std::cout << "Found value 5: " << *it << std::endl;
		*it = 50;
		std::cout << "Changed value to 50" << std::endl;
		std::cout << "Value after change: " << *easyfind(vec, 50) << std::endl;
		std::cout << "Searching for non-existent value 100: " << std::endl;
		std::cout << *easyfind(vec, 100) << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "\n=== Const container test ===" << std::endl;
	std::list<int> temp;
	for (int i = 0; i < 10; i++)
		temp.push_back(i);
	const std::list<int>& lst = temp;
	try {
		std::list<int>::const_iterator it = easyfind(lst, 5);
		std::cout << "Found value 5: " << *it << std::endl;
		// *it = 50; // This will cause a compilation error
		std::cout << "Searching for non-existent value 100: " << std::endl;
		std::cout << *easyfind(lst, 100) << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
