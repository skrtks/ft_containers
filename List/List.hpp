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

namespace ft {
	template <class T, class Alloc = std::allocator<T>>
	class List {
	public:
		List();
		virtual ~List();
		List(const List& obj);
		List& operator=(const List& obj);

		// types
		typedef T value_type;
		typedef Alloc allocator_type;
		typedef typename allocator_type::reference reference;
		typedef typename allocator_type::const_reference const_reference;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;
//		typedef BidirectionalIterator<value_type, node_pointer>			iterator;
//		typedef ConstBidirectionalIterator<value_type, node_pointer>	const_iterator;
//		typedef RevBidirectionalIterator<value_type, node_pointer>		reverse_iterator;
//		typedef ConstRevBidirectionalIterator<value_type, node_pointer>	const_reverse_iterator;
		typedef reverse_iterator<iterator> reverse_iterator;
		typedef reverse_iterator<const_iterator> const_reverse_iterator;
	};
}

#endif //LIST_HPP