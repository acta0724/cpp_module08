#include <iostream>
#include <vector>
#include <algorithm>
#include "Span.hpp"

int main() {
	std::cout << "=== Basic Test ===" << std::endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	std::cout << "\n=== Multiple Elements Test ===" << std::endl;
	Span sp2 = Span(10000);
	std::vector<int> numbers;
	for (int i = 0; i < 1000; ++i) {
		numbers.push_back(i * 2);
	}
	try {
		sp2.addNumber(numbers.begin(), numbers.end());
		std::cout << "Successfully added 1000 random numbers" << std::endl;
		std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp2.longestSpan() << std::endl;
		std::cout << "\nTrying to add more elements than capacity..." << std::endl;
		std::vector<int> more_numbers(10000);
		for (int i = 0; i < 10000; ++i) {
			more_numbers.push_back(i * 2);
		}
		sp2.addNumber(more_numbers.begin(), more_numbers.end());
	} catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
	return 0;
}
