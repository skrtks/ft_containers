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
	public:
		typedef T			value_type;
		typedef Container	container_type;
		typedef size_t		size_type;

		explicit stack (const container_type& ctnr = container_type()): _ctnr(ctnr) {}


		bool empty() const {
			return _ctnr.empty();
		}

		size_type size() const {
			return _ctnr.size();
		}

		value_type& top() {
			return _ctnr.back();
		}

		const value_type& top() const {
			return _ctnr.back();
		}

		void push (const value_type& val) {
			_ctnr.push_back(val);
		}

		void pop() {
			_ctnr.pop_back();
		}

		// Relational operators
		friend bool	operator==(const stack<value_type , container_type>& lhs, const stack<value_type , container_type>& rhs) {
			return (lhs._ctnr == rhs._ctnr);
		}
		friend bool operator!=(const stack<value_type , container_type>& lhs, const stack<value_type , container_type>& rhs) {
			return (lhs._ctnr != rhs._ctnr);
		}
		friend bool	operator<(const stack<value_type , container_type>& lhs, const stack<value_type , container_type>& rhs) {
			return (lhs._ctnr < rhs._ctnr);
		}
		friend bool operator>(const stack<value_type , container_type>& lhs, const stack<value_type , container_type>& rhs) {
			return (lhs._ctnr > rhs._ctnr);
		}
		friend bool	operator<=(const stack<value_type , container_type>& lhs, const stack<value_type , container_type>& rhs) {
			return (lhs._ctnr <= rhs._ctnr);
		}
		friend bool operator>=(const stack<value_type , container_type>& lhs, const stack<value_type , container_type>& rhs) {
			return (lhs._ctnr >= rhs._ctnr);
		}

	private:
		container_type _ctnr;
	};

} // end ft

#endif //STACK_HPP
