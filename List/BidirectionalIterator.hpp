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
			return _ptr->_data;
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
			return &this->_ptr->_data;
		}
		bool					operator==(const BidirectionalIterator &obj) {
			return (_ptr == obj._ptr);
		}
		bool					operator!=(const BidirectionalIterator &obj) {
			return (_ptr != obj._ptr);
		}
	};

	template < typename T, typename N, class Category = std::bidirectional_iterator_tag >
	class ConstBidirectionalIterator {
		ConstBidirectionalIterator& operator=(const ConstBidirectionalIterator& obj);
	public:
		typedef T							value_type;
		typedef value_type&					reference;
		typedef const value_type&			constReference;
		typedef value_type*					pointer;
		typedef N                           node_pointer;
		typedef size_t						size_type;
		typedef ptrdiff_t					difference_type;
		typedef Category					iterator_category;
		typedef ConstBidirectionalIterator		self_type;
	protected:
		node_pointer _ptr;
	public:
		ConstBidirectionalIterator(): _ptr(NULL) {}
		explicit ConstBidirectionalIterator(node_pointer node): _ptr(node) {}
		virtual ~ConstBidirectionalIterator() {}
		ConstBidirectionalIterator(const ConstBidirectionalIterator& obj) { *this = obj;}
		constReference				operator*() {
			return _ptr->_data;
		}
		ConstBidirectionalIterator	operator++(int) { // Overload postfix ++
			ConstBidirectionalIterator	out(*this);
			if (_ptr->_next) {
				_ptr = _ptr->_next;
			}
			return out;
		}
		ConstBidirectionalIterator&	operator++() { // Overload prefix ++
			if (_ptr->_next) {
				_ptr = _ptr->_next;
			}
			return *this;
		}
		ConstBidirectionalIterator	operator--(int) { // Overload postfix --
			ConstBidirectionalIterator	out(*this);
			if (_ptr->_previous) {
				_ptr = _ptr->_previous;
			}
			return out;
		}
		ConstBidirectionalIterator&	operator--() { // Overload prefix --
			if (_ptr->_previous) {
				_ptr = _ptr->_previous;
			}
			return *this;
		}
		pointer					operator->() {
			return &this->_ptr->_data;
		}
		bool					operator==(const ConstBidirectionalIterator &obj) {
			return (_ptr == obj._ptr);
		}
		bool					operator!=(const ConstBidirectionalIterator &obj) {
			return (_ptr != obj._ptr);
		}
	};

	template < typename T, typename N, class Category = std::bidirectional_iterator_tag >
	class RevBidirectionalIterator {
	public:
		typedef T							value_type;
		typedef value_type&					reference;
		typedef value_type*					pointer;
		typedef N                           node_pointer;
		typedef size_t						size_type;
		typedef ptrdiff_t					difference_type;
		typedef Category					iterator_category;
		typedef RevBidirectionalIterator		self_type;
	protected:
		node_pointer _ptr;
	public:
		RevBidirectionalIterator(): _ptr(NULL) {}
		explicit RevBidirectionalIterator(node_pointer node): _ptr(node) {}
		virtual ~RevBidirectionalIterator() {}
		RevBidirectionalIterator(const RevBidirectionalIterator& obj) { *this = obj;}
		RevBidirectionalIterator& operator=(const RevBidirectionalIterator& obj) {
			if (&obj != this) {
				_ptr = obj._ptr;
			}
			return *this;
		}

		reference				operator*() {
			return _ptr->_data;
		}
		RevBidirectionalIterator	operator++(int) { // Overload postfix ++
			RevBidirectionalIterator	out(*this);
			if (_ptr->_previous) {
				_ptr = _ptr->_previous;
			}
			return out;
		}
		RevBidirectionalIterator&	operator++() { // Overload prefix ++
			if (_ptr->_previous) {
				_ptr = _ptr->_previous;
			}
			return *this;
		}
		RevBidirectionalIterator	operator--(int) { // Overload postfix --
			RevBidirectionalIterator	out(*this);
			if (_ptr->_next) {
				_ptr = _ptr->_next;
			}
			return out;
		}
		RevBidirectionalIterator&	operator--() { // Overload prefix --
			if (_ptr->_next) {
				_ptr = _ptr->_next;
			}
			return *this;
		}
		pointer					operator->() {
			return &this->_ptr->_data;
		}
		bool					operator==(const RevBidirectionalIterator &obj) {
			return (_ptr == obj._ptr);
		}
		bool					operator!=(const RevBidirectionalIterator &obj) {
			return (_ptr != obj._ptr);
		}
	};

	template < typename T, typename N, class Category = std::bidirectional_iterator_tag >
	class ConstRevBidirectionalIterator {
		ConstRevBidirectionalIterator& operator=(const ConstRevBidirectionalIterator& obj);
	public:
		typedef T							value_type;
		typedef value_type&					reference;
		typedef const value_type&			constReference;
		typedef value_type*					pointer;
		typedef N                           node_pointer;
		typedef size_t						size_type;
		typedef ptrdiff_t					difference_type;
		typedef Category					iterator_category;
		typedef ConstRevBidirectionalIterator		self_type;
	protected:
		node_pointer _ptr;
	public:
		ConstRevBidirectionalIterator(): _ptr(NULL) {}
		explicit ConstRevBidirectionalIterator(node_pointer node): _ptr(node) {}
		virtual ~ConstRevBidirectionalIterator() {}
		ConstRevBidirectionalIterator(const ConstRevBidirectionalIterator& obj) { *this = obj;}

		constReference					operator*() {
			return _ptr->_data;
		}
		ConstRevBidirectionalIterator	operator++(int) { // Overload postfix ++
			ConstRevBidirectionalIterator	out(*this);
			if (_ptr->_previous) {
				_ptr = _ptr->_previous;
			}
			return out;
		}
		ConstRevBidirectionalIterator&	operator++() { // Overload prefix ++
			if (_ptr->_previous) {
				_ptr = _ptr->_previous;
			}
			return *this;
		}
		ConstRevBidirectionalIterator	operator--(int) { // Overload postfix --
			ConstRevBidirectionalIterator	out(*this);
			if (_ptr->_next) {
				_ptr = _ptr->_next;
			}
			return out;
		}
		ConstRevBidirectionalIterator&	operator--() { // Overload prefix --
			if (_ptr->_next) {
				_ptr = _ptr->_next;
			}
			return *this;
		}
		pointer					operator->() {
			return &this->_ptr->_data;
		}
		bool					operator==(const ConstRevBidirectionalIterator &obj) {
			return (_ptr == obj._ptr);
		}
		bool					operator!=(const ConstRevBidirectionalIterator &obj) {
			return (_ptr != obj._ptr);
		}
	};

}

#endif //BIDIRECTIONALITERATOR_HPP
