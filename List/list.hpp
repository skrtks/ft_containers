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
//	typedef RevBidirectionalIterator<value_type, node_pointer>		reverse_iterator;
//	typedef ConstRevBidirectionalIterator<value_type, node_pointer>	const_reverse_iterator;

	// Default constructor
	explicit list(const allocator_type& alloc = allocator_type()): _allocator(alloc) {
		_node = NULL;
		_head = new Node<value_type>();
		_tail = new Node<value_type>();
		setHead(_tail);
		setTail(_head);
		_size = 0;
	}
	virtual ~list() {}

	// Iterators
	iterator begin() {
		if (_size == 0)
			return iterator(_head);
		return iterator(getHead());
	}
	iterator end() {
		if (_size == 0)
			return iterator(_tail);
		return iterator(getTail());
	}

	void push_back(value_type element) {
		Node<value_type>* tmp;
		if (!_node) {
			_node = new Node<value_type>(element);
			setHead(_node);
			setTail(_node);
			_size++;
		}
		else {
			_node = new Node<value_type>(element);
			_node->_previous = getTail();
			tmp = getTail();
			tmp->_next = _node;
			setTail(_node);
			_size++;
		}
	}

	node_pointer getHead() const {
		return _head->_next;
	}

	node_pointer getTail() const {
		return _tail->_previous;
	}

	void setHead(node_pointer node) {
		_head->_next = node;
	}

	void setTail(node_pointer node) {
		_tail->_previous = node;
	}


private:
	node_pointer	_node;
	node_pointer	_head;
	node_pointer	_tail;
	size_type		_size;
	allocator_type	_allocator;
};

}

#endif //LIST_HPP
