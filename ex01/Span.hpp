#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iterator>

class Span {
 private:
	std::vector<int> _vec;
	size_t _size;
 public:
	Span(size_t size);
	~Span();
	Span(const Span &other);
	Span &operator=(const Span &other);
	template <typename T>
	void addNumber(T begin, T end) {
		if (_vec.size() + std::distance(begin, end) > _size)
			throw std::runtime_error("Span is full");
		_vec.insert(_vec.end(), begin, end);
	}
	void addNumber(int num);
	int shortestSpan() const;
	int longestSpan() const;
};


#endif