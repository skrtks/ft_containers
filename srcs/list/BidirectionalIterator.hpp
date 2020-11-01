/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   BidirectionalIterator.hpp                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: sam <sam@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/20 18:55:49 by sam           #+#    #+#                 */
/*   Updated: 2020/10/20 18:55:49 by sam           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIDIRECTIONALITERATOR_HPP
#define BIDIRECTIONALITERATOR_HPP

#include <cstddef>

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
		BidirectionalIterator(const BidirectionalIterator& obj) { *this = obj;}
		BidirectionalIterator& operator=(const BidirectionalIterator& obj) {
			if (&obj != this) {
				_ptr = obj._ptr;
			}
			return *this;
		}
		virtual ~BidirectionalIterator() {}

		BidirectionalIterator	operator++(int) { // Overload postfix ++
			BidirectionalIterator	ret(*this);
			if (_ptr->getNext()) {
				_ptr = _ptr->getNext();
			}
			return ret;
		}
		BidirectionalIterator&	operator++() { // Overload prefix ++
			if (_ptr->getNext()) {
				_ptr = _ptr->getNext();
			}
			return *this;
		}
		BidirectionalIterator	operator--(int) { // Overload postfix --
			BidirectionalIterator	ret(*this);
			if (_ptr->getPrevious()) {
				_ptr = _ptr->getPrevious();
			}
			return ret;
		}
		BidirectionalIterator&	operator--() { // Overload prefix --
			if (_ptr->getPrevious()) {
				_ptr = _ptr->getPrevious();
			}
			return *this;
		}
		reference	operator*() {
			return _ptr->_data;
		}
		pointer	operator->() {
			return &this->_ptr->_data;
		}
		bool	operator==(const BidirectionalIterator &obj) {
			return (_ptr == obj._ptr);
		}
		bool	operator!=(const BidirectionalIterator &obj) {
			return (_ptr != obj._ptr);
		}
		bool	operator>=(const BidirectionalIterator &obj) {
			return (_ptr >= obj._ptr);
		}

		node_pointer getPtr() const {
			return _ptr;
		}
	};

	template < typename T, typename N, class Category = std::bidirectional_iterator_tag >
	class ConstBidirectionalIterator: public BidirectionalIterator<T, N> {
	public:
		typedef T							value_type;
		typedef value_type&					reference;
		typedef const value_type&			const_reference;
		typedef value_type*					pointer;
		typedef const value_type*			const_pointer;
		typedef N                           node_pointer;
		typedef size_t						size_type;
		typedef ptrdiff_t					difference_type;
		typedef Category					iterator_category;
		typedef ConstBidirectionalIterator		self_type;
	public:
		ConstBidirectionalIterator(): BidirectionalIterator<T, N>() {}
		explicit ConstBidirectionalIterator(node_pointer node): BidirectionalIterator<T, N>(node) {}
		virtual ~ConstBidirectionalIterator() {}
		ConstBidirectionalIterator(const ConstBidirectionalIterator& obj) { *this = obj;}
		ConstBidirectionalIterator(const BidirectionalIterator<T, N>& obj) { *this = obj;}
		ConstBidirectionalIterator& operator=(const ConstBidirectionalIterator& obj) {
			if (&obj != this) {
				this->_ptr = obj.getPtr();
			}
			return *this;
		}
		ConstBidirectionalIterator& operator=(const BidirectionalIterator<T, N>& obj) {
			if (&obj != this) {
				this->_ptr = obj.getPtr();
			}
			return *this;
		}
		const_reference	operator*() {
			return this->_ptr->_data;
		}
		const_pointer	operator->() {
			return &this->_ptr->_data;
		}
		bool	operator==(const ConstBidirectionalIterator &obj) {
			return (this->_ptr == obj._ptr);
		}
		bool	operator!=(const ConstBidirectionalIterator &obj) {
			return (this->_ptr != obj._ptr);
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

		RevBidirectionalIterator	operator++(int) { // Overload postfix ++
			RevBidirectionalIterator	ret(*this);
			if (_ptr->getPrevious()) {
				_ptr = _ptr->getPrevious();
			}
			return ret;
		}
		RevBidirectionalIterator&	operator++() { // Overload prefix ++
			if (_ptr->getPrevious()) {
				_ptr = _ptr->getPrevious();
			}
			return *this;
		}
		RevBidirectionalIterator	operator--(int) { // Overload postfix --
			RevBidirectionalIterator	ret(*this);
			if (_ptr->getNext()) {
				_ptr = _ptr->getNext();
			}
			return ret;
		}
		RevBidirectionalIterator&	operator--() { // Overload prefix --
			if (_ptr->getNext()) {
				_ptr = _ptr->getNext();
			}
			return *this;
		}
		reference	operator*() {
			return _ptr->_data;
		}
		pointer	operator->() {
			return &this->_ptr->_data;
		}
		bool	operator==(const RevBidirectionalIterator &obj) {
			return (_ptr == obj._ptr);
		}
		bool	operator!=(const RevBidirectionalIterator &obj) {
			return (_ptr != obj._ptr);
		}

		node_pointer getPtr() const {
			return _ptr;
		}
	};

	template < typename T, typename N, class Category = std::bidirectional_iterator_tag >
	class ConstRevBidirectionalIterator: public RevBidirectionalIterator<T, N> {
	public:
		typedef T							value_type;
		typedef value_type&					reference;
		typedef const value_type&			const_reference;
		typedef value_type*					pointer;
		typedef const value_type*			const_pointer;
		typedef N                           node_pointer;
		typedef size_t						size_type;
		typedef ptrdiff_t					difference_type;
		typedef Category					iterator_category;
		typedef ConstRevBidirectionalIterator		self_type;
	public:
		ConstRevBidirectionalIterator(): RevBidirectionalIterator<T, N>() {}
		explicit ConstRevBidirectionalIterator(node_pointer node): RevBidirectionalIterator<T, N>(node) {}
		virtual ~ConstRevBidirectionalIterator() {}
		ConstRevBidirectionalIterator(const ConstRevBidirectionalIterator& obj) { *this = obj;}
		ConstRevBidirectionalIterator(const RevBidirectionalIterator<T, N>& obj) { *this = obj;}
		ConstRevBidirectionalIterator& operator=(const ConstRevBidirectionalIterator& obj) {
			if (&obj != this) {
				this->_ptr = obj.getPtr();
			}
			return *this;
		}
		ConstRevBidirectionalIterator& operator=(const RevBidirectionalIterator<T, N>& obj) {
			if (&obj != this) {
				this->_ptr = obj.getPtr();
			}
			return *this;
		}
		const_reference	operator*() {
			return this->_ptr->_data;
		}
		const_pointer	operator->() {
			return &this->_ptr->_data;
		}
		bool	operator==(const ConstRevBidirectionalIterator &obj) {
			return (this->_ptr == obj._ptr);
		}
		bool	operator!=(const ConstRevBidirectionalIterator &obj) {
			return (this->_ptr != obj._ptr);
		}
	};

}

#endif //BIDIRECTIONALITERATOR_HPP
