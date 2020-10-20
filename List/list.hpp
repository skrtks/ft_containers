/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   List.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: skorteka <skorteka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/14 11:57:47 by skorteka      #+#    #+#                 */
/*   Updated: 2020/10/14 11:57:47 by skorteka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
#define LIST_HPP

#include <memory>
#include <iterator>
#include "Node.hpp"
#include "BidirectionalIterator.hpp"
#include "Traits.hpp"

namespace ft {

template <class T, class Alloc = std::allocator<T> >
class list {
public:
	// types
	typedef T			value_type;
	typedef Alloc		allocator_type;
	typedef T			&reference;
	typedef const T		&const_reference;
	typedef T			*pointer;
	typedef const T		*const_pointer;
	typedef Node<T>		*node_pointer;
	typedef ptrdiff_t	difference_type;
	typedef size_t		size_type;
	typedef BidirectionalIterator<value_type, node_pointer>			iterator;
	typedef ConstBidirectionalIterator<value_type, node_pointer>	const_iterator;
	typedef RevBidirectionalIterator<value_type, node_pointer>		reverse_iterator;
	typedef ConstRevBidirectionalIterator<value_type, node_pointer>	const_reverse_iterator;

	// Constructors/Destructor:
	explicit list(const allocator_type& alloc = allocator_type()): _allocator(alloc) {
		_head = new Node<value_type>();
		_tail = new Node<value_type>();
		_head->_next = _tail;
		_tail->_previous = _head;
		_size = 0;
	}
//	list(size_type n, const value_type& val = value_type(),
//		 const allocator_type& alloc = allocator_type()): _allocator(alloc) {
//		_head = new Node<value_type>();
//		_tail = new Node<value_type>();
//		_head->_next = _tail;
//		_tail->_previous = _head;
//
//	}
	virtual ~list() {
		while (_size) {
			pop_front();
		}
		delete _head;
		delete _tail;
	}

	// Iterators:
	iterator begin() {return iterator(_head->_next);}
	iterator end() {return iterator(_tail);}
	const_iterator begin() const {return const_iterator(_head->_next);}
	const_iterator end() const {return const_iterator(_tail);}
	reverse_iterator rbegin() {return reverse_iterator(_tail->_previous);}
	reverse_iterator rend() {return reverse_iterator(_head);}
	const_reverse_iterator rbegin() const {return const_reverse_iterator(_tail->_previous);}
	const_reverse_iterator rend() const {return const_reverse_iterator(_head);}

	// Capacity:
	// todo

	// Element access:
	// todo

	// Modifiers:

	template <class InputIterator>
	void assign (InputIterator first, InputIterator last, typename enable_if<check_category<InputIterator>::value, InputIterator>::type * = 0) {
		clear();
		while (first != last) {
			push_back(*first);
			first++;
		}
	}

	void assign (size_type n, const value_type& val) {
		clear();
		for (size_type i = 0; i < n; i++) {
			push_back(val);
		}
	}

	void push_back(const value_type &element) {
		Node<value_type>* node;
		node = new Node<value_type>(element);
		node->_previous = _tail->_previous;
		_tail->_previous->_next = node;
		_tail->_previous = node;
		node->_next = _tail;
		_size++;
	}

	void push_front(const value_type &element) {
		Node<value_type>* node;
		node = new Node<value_type>(element);
		node->_previous = _head;
		node->_next = _head->_next;
		_head->_next->_previous = node;
		_head->_next = node;
		_size++;
	}

	void pop_front() {
		if (_size) {
			Node<value_type>* node;
			node = _head->_next;
			_head->_next = node->_next;
			node->_next->_previous = _head;
			_size--;
			delete node;
		}
	}

	void pop_back() {
		if (_size) {
			Node<value_type>* node;
			node = _tail->_previous;
			_tail->_previous = node->_previous;
			node->_previous->_next = _tail;
			_size--;
			delete node;
		}
	}

	void	clear() {
		while (_size) {
			pop_back();
		}
	}

	// Operations:
	// todo

private:
	node_pointer	_head;
	node_pointer	_tail;
	size_type		_size;
	allocator_type	_allocator;
};

}

#endif //LIST_HPP
