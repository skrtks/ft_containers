/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   queue.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: skorteka <skorteka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 13:39:32 by skorteka      #+#    #+#                 */
/*   Updated: 2020/10/29 13:39:32 by skorteka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "Node.hpp"
#include "BidirectionalIterator.hpp"
#include "Traits.hpp"
#include <memory>
#include <iterator>
#include <deque>
#include <algorithm>
#include <cstddef>

namespace ft {

	template <class T, class Container = std::deque<T>, class Alloc = std::allocator<T> >
	class queue {
	public:
		typedef T			value_type;
		typedef Container	container_type;
		typedef size_t		size_type;

		explicit queue(const container_type& ctnr = container_type()): _ctnr(ctnr) {}


		bool empty() const {
			return _ctnr.empty();
		}

		size_type size() const {
			return _ctnr.size();
		}

		value_type& front() {
			return _ctnr.front();
		}

		const value_type& front() const {
			return _ctnr.front();
		}

		value_type& back() {
			return _ctnr.back();
		}

		const value_type& back() const {
			return _ctnr.back();
		}

		void push (const value_type& val) {
			_ctnr.push_back(val);
		}

		void pop() {
			_ctnr.pop_front();
		}

		// Relational operators
		friend bool	operator==(const queue<value_type , container_type>& lhs, const queue<value_type , container_type>& rhs) {
			return (lhs._ctnr == rhs._ctnr);
		}
		friend bool operator!=(const queue<value_type , container_type>& lhs, const queue<value_type , container_type>& rhs) {
			return (lhs._ctnr != rhs._ctnr);
		}
		friend bool	operator<(const queue<value_type , container_type>& lhs, const queue<value_type , container_type>& rhs) {
			return (lhs._ctnr < rhs._ctnr);
		}
		friend bool operator>(const queue<value_type , container_type>& lhs, const queue<value_type , container_type>& rhs) {
			return (lhs._ctnr > rhs._ctnr);
		}
		friend bool	operator<=(const queue<value_type , container_type>& lhs, const queue<value_type , container_type>& rhs) {
			return (lhs._ctnr <= rhs._ctnr);
		}
		friend bool operator>=(const queue<value_type , container_type>& lhs, const queue<value_type , container_type>& rhs) {
			return (lhs._ctnr >= rhs._ctnr);
		}

	private:
		container_type _ctnr;
	};

} // end ft

#endif //QUEUE_HPP
