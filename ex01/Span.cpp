#include "Span.hpp"

Span::Span(size_t size) : _size(size) {}

Span::~Span() {}

Span::Span(const Span &other) : _vec(other._vec), _size(other._size) {}

Span &Span::operator=(const Span &other) {
	if (this != &other) {
		_size = other._size;
		_vec = other._vec;
	}
	return *this;
}

void Span::addNumber(int num) {
	if (_vec.size() >= _size)
		throw std::runtime_error("Span is full");
	_vec.push_back(num);
}

int Span::shortestSpan() const {
	int min_span;

	if (_vec.size() < 2)
		throw std::runtime_error("Not enough elements");
	std::vector<int> sorted_vec = _vec;
	sort(sorted_vec.begin(), sorted_vec.end());
	min_span = sorted_vec[1] - sorted_vec[0];
	for (size_t i = 2; i < sorted_vec.size(); i++) {
		min_span = std::min(min_span, sorted_vec[i] - sorted_vec[i - 1]);
	}
	return min_span;
}

int Span::longestSpan() const {
	if (_vec.size() < 2)
		throw std::runtime_error("Not enough elements");
	int min = *std::min_element(_vec.begin(), _vec.end());
	int max = *std::max_element(_vec.begin(), _vec.end());
	return max - min;
}
