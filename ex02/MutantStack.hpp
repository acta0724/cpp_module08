#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
 public:
	// Orthodox Canonical Form
	MutantStack();
	~MutantStack();
	MutantStack(const MutantStack &other);
	MutantStack &operator=(const MutantStack &other);

	// Iterator typedefs for convenience
	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
	typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

	// Iterator methods - normal iterators
	iterator begin();
	const_iterator begin() const;
	iterator end();
	const_iterator end() const;

	// Iterator methods - reverse iterators
	reverse_iterator rbegin();
	const_reverse_iterator rbegin() const;
	reverse_iterator rend();
	const_reverse_iterator rend() const;
};

#include "MutantStack.tpp"

#endif
