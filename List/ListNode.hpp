/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ListNode.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: skorteka <skorteka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/14 14:19:48 by skorteka      #+#    #+#                 */
/*   Updated: 2020/10/14 14:19:48 by skorteka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LISTNODE_HPP
#define LISTNODE_HPP

namespace ft {

template <class T>
class ListNode {
	ListNode	_next;
	ListNode	_previous;
	T			_data;
private:
	ListNode(): _next(0), _previous(0), _data(0) {}
	explicit ListNode(const T &obj): _next(0), _previous(0), _data(new T(obj)) {}
	virtual ~ListNode() {};
	ListNode& operator=(const ListNode& obj) {
		if (&obj != this) {
			delete _data;
			_data = new T(obj._data);
			_next = obj._next;
			_previous = obj._previous;
		}
	}
};

}

#endif //LISTNODE_HPP
