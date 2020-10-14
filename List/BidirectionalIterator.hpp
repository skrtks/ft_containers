#ifndef BIDIRECTIONALITERATOR_HPP
#define BIDIRECTIONALITERATOR_HPP

namespace ft {

#include "ListNode.hpp"

template <class T>
class BidirectionalIterator {
	ft::ListNode<T> _head;
	T _data;
public:
	BidirectionalIterator();
	virtual ~BidirectionalIterator();
	BidirectionalIterator(const BidirectionalIterator& obj);
	BidirectionalIterator& operator=(const BidirectionalIterator& obj);
};

}

#endif //BIDIRECTIONALITERATOR_HPP
