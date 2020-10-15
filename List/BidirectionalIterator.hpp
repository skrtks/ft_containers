#ifndef BIDIRECTIONALITERATOR_HPP
#define BIDIRECTIONALITERATOR_HPP

#include "ListNode.hpp"

template <class T>
class BidirectionalIterator {
protected:
	ListNode<T> *_ptr;
public:
	BidirectionalIterator(): _ptr(0) {}
	explicit BidirectionalIterator(ListNode<T> *node): _ptr(node) {}
	virtual ~BidirectionalIterator() {}
	BidirectionalIterator(const BidirectionalIterator& obj) { _ptr = obj._ptr;}
	BidirectionalIterator& operator=(const BidirectionalIterator& obj) {
		if (&obj != this) {
			_ptr = obj._ptr;
		}
	}
	BidirectionalIterator	operator++(int) {
		BidirectionalIterator	out(*this);
		_ptr = _ptr->getNext();
		return out;
	}
	BidirectionalIterator&	operator++() {
		_ptr = _ptr->getNext();
		return *this;
	}
};


#endif //BIDIRECTIONALITERATOR_HPP
