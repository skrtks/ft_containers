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
class List {
public:
	// types
	typedef T										value_type;
	typedef Alloc									allocator_type;
	typedef ft::BidirectionalIterator<value_type>	iterator;
	typedef typename allocator_type::size_type		size_type;
//	typedef typename allocator_type::reference reference;
//	typedef typename allocator_type::const_reference const_reference;
//	typedef typename allocator_type::pointer pointer;
//	typedef typename allocator_type::const_pointer const_pointer;


	List(): _head(0), _node(0) {}
	virtual ~List() {}
	List(const List& obj): _node(new ListNode<value_type>(obj)), _head(_node) {}
	List& operator=(const List& obj) {
		if (&obj != this) {
			// Iterate over list and delete

		}
	}

	iterator begin() {return _head}


private:
	ListNode<value_type>	_node;
	ListNode<value_type>	_head;
	ListNode<value_type>	_tail;
	size_type				_size;
	allocator_type			_allocator;

	void deepCopy() {

	};
};

}

#endif //LIST_HPP
