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
//	Also need const version!

	// Default constructor
	explicit list(const allocator_type& alloc = allocator_type()): _allocator(alloc) {
		_head = new Node<value_type>();
		_tail = new Node<value_type>();
		_head->_next = _tail;
		_tail->_previous = _head;
		_size = 0;
	}
	// Fill constructor
//	list(size_type n, const value_type& val = value_type(),
//		 const allocator_type& alloc = allocator_type()): _allocator(alloc) {
//		_head = new Node<value_type>();
//		_tail = new Node<value_type>();
//		_head->_next = _tail;
//		_tail->_previous = _head;
//
//	}
	virtual ~list() {}

	// Iterators
	iterator begin() {return iterator(_head->_next);}
	iterator end() {return iterator(_tail);}
	const_iterator begin() const {return const_iterator(_head->_next);}
	const_iterator end() const {return const_iterator(_tail);}
	reverse_iterator rbegin() {return reverse_iterator(_tail->_previous);}
	reverse_iterator rend() {return reverse_iterator(_head);}
	const_reverse_iterator rbegin() const {return const_reverse_iterator(_tail->_previous);}
	const_reverse_iterator rend() const {return const_reverse_iterator(_head);}

	void push_back(const value_type &element) {
		Node<value_type>* _node;
		_node = new Node<value_type>(element);
		_node->_previous = _tail->_previous;
		_tail->_previous->_next = _node;
		_tail->_previous = _node;
		_node->_next = _tail;
		_size++;
	}

	void push_front(const value_type &element) {
		Node<value_type>* _node;
		_node = new Node<value_type>(element);
		_node->_previous = _head;
		_node->_next = _head->_next;
		_head->_next->_previous = _node;
		_head->_next = _node;
		_size++;
	}

private:
	node_pointer	_head;
	node_pointer	_tail;
	size_type		_size;
	allocator_type	_allocator;
};

}

#endif //LIST_HPP
