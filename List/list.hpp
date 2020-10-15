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
#include "ListNode.hpp"
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
	typedef ListNode<T>	*node_pointer;
	typedef ptrdiff_t	difference_type;
	typedef size_t		size_type;
	typedef BidirectionalIterator<value_type>			iterator;
//	typedef ConstBidirectionalIterator<value_type, node_pointer>	const_iterator;
//	typedef RevBidirectionalIterator<value_type, node_pointer>		reverse_iterator;
//	typedef ConstRevBidirectionalIterator<value_type, node_pointer>	const_reverse_iterator;

	// Default constructor
	explicit list(const allocator_type& alloc = allocator_type()): _allocator(alloc) {
		_node = NULL;
		_head = new ListNode<value_type>();
		_tail = new ListNode<value_type>();
		_head->_next = _tail;
		_tail->_previous = _head;
		_size = 0;
	}
	virtual ~list() {}

//	list(const list& obj) {
//
//	}
//	list& operator=(const list& obj) {
//		if (&obj != this) {
//			// Iterate over list and delete
//
//		}
//	}

	iterator begin() {return iterator(_head->_next);}

	void push_back(value_type element) {
		if (!_node) {
			_node = new ListNode<value_type>(element);
			_head->setNext(_node);
			_tail->setPrevious(_node);
			_size++;
		}
		else {
			_node = new ListNode<value_type>(element);
			_node->setPrevious(_tail->getPrevious());
			_tail->_previous->_next = _node;
			_tail->_previous = _node;
			_tail = _node;
			_size++;
		}
	}


private:
	ListNode<value_type>	*_node;
	ListNode<value_type>	*_head;
	ListNode<value_type>	*_tail;
	size_type				_size;
	allocator_type			_allocator;
};

}

#endif //LIST_HPP
