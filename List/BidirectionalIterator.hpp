#ifndef BIDIRECTIONALITERATOR_HPP
#define BIDIRECTIONALITERATOR_HPP

#include "Node.hpp"

namespace ft {

	template < typename T, typename N, class Category = std::bidirectional_iterator_tag >
	class BidirectionalIterator {
	public:
		typedef T							value_type;
		typedef value_type&					reference;
		typedef value_type*					pointer;
		typedef N                           node_pointer;
		typedef size_t						size_type;
		typedef ptrdiff_t					difference_type;
		typedef Category					iterator_category;
		typedef BidirectionalIterator		self_type;
	protected:
		node_pointer _ptr;
	public:
		BidirectionalIterator(): _ptr(NULL) {}
		explicit BidirectionalIterator(node_pointer node): _ptr(node) {}
		virtual ~BidirectionalIterator() {}
		BidirectionalIterator(const BidirectionalIterator& obj) { *this = obj;}
		BidirectionalIterator& operator=(const BidirectionalIterator& obj) {
			if (&obj != this) {
				_ptr = obj._ptr;
			}
			return *this;
		}
		reference				operator*() {
			return *_ptr->_data;
		}
		BidirectionalIterator	operator++(int) { // Overload postfix ++
			BidirectionalIterator	out(*this);
			if (_ptr->_next) {
				_ptr = _ptr->_next;
			}
			return out;
		}
		BidirectionalIterator&	operator++() { // Overload prefix ++
			if (_ptr->_next) {
				_ptr = _ptr->_next;
			}
			return *this;
		}
		BidirectionalIterator	operator--(int) { // Overload postfix --
			BidirectionalIterator	out(*this);
			if (_ptr->_previous) {
				_ptr = _ptr->_previous;
			}
			return out;
		}
		BidirectionalIterator&	operator--() { // Overload prefix --
			if (_ptr->_previous) {
				_ptr = _ptr->_previous;
			}
			return *this;
		}
		pointer					operator->() {
			return this->_ptr->_data;
		}
		bool					operator==(const BidirectionalIterator &obj) {
			return (_ptr == obj._ptr);
		}
		bool					operator!=(const BidirectionalIterator &obj) {
			return (_ptr != obj._ptr);
		}
	};
}

#endif //BIDIRECTIONALITERATOR_HPP
