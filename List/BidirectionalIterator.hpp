#ifndef BIDIRECTIONALITERATOR_HPP
#define BIDIRECTIONALITERATOR_HPP

#include "Node.hpp"

template <class T>
class BidirectionalIterator {
protected:
	Node<T> *_ptr;
public:
	BidirectionalIterator(): _ptr(0) {}
	explicit BidirectionalIterator(Node<T> *node): _ptr(node) {}
	virtual ~BidirectionalIterator() {}
	BidirectionalIterator(const BidirectionalIterator& obj) { _ptr = obj._ptr;}
	BidirectionalIterator& operator=(const BidirectionalIterator& obj) {
		if (&obj != this) {
			_ptr = obj._ptr;
		}
	}
	BidirectionalIterator	operator++(int) { // Overload postfix ++
		BidirectionalIterator	out(*this);
		_ptr = _ptr->_next;
		return out;
	}
	BidirectionalIterator&	operator++() { // Overload prefix ++
		_ptr = _ptr->_next;
		return *this;
	}
	BidirectionalIterator	operator--(int) { // Overload postfix --
		BidirectionalIterator	out(*this);
		_ptr = _ptr->_previous;
		return out;
	}
	BidirectionalIterator&	operator--() { // Overload prefix --
		_ptr = _ptr->_previous;
		return *this;
	}
	T&	operator*() {
		return *_ptr->_data;
	}
//	T*	operator->() {
//		return &(this->_ptr->_data);
//	}
};

#endif //BIDIRECTIONALITERATOR_HPP
