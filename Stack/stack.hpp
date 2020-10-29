/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: skorteka <skorteka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 11:44:48 by skorteka      #+#    #+#                 */
/*   Updated: 2020/10/29 11:44:48 by skorteka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
#define STACK_HPP

#include <memory>
#include <iterator>
#include "Node.hpp"
#include "BidirectionalIterator.hpp"
#include "Traits.hpp"
#include <algorithm>
#include <cstddef>

#include <deque> // todo This is now the default container

namespace ft {

	template <class T, class Container = std::deque<T>, class Alloc = std::allocator<T> >
	class stack {
		typedef T			value_type;
		typedef Container	container_type;
		typedef size_t		size_type;
	};
} // end ft

#endif //STACK_HPP
