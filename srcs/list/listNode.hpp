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

#include <cstdlib>

template <class T>
class listNode {
public:
	listNode	*_next;
	listNode	*_previous;
	T		_data;

	explicit listNode(): _next(NULL), _previous(NULL), _data(T()) {}
	explicit listNode(T element): _next(NULL), _previous(NULL), _data(T(element)) {}
	virtual ~listNode() {};
	listNode& operator=(const listNode& obj) {
		_data = obj._data;
		_next = obj._next;
		_previous = obj._previous;
		return *this;
	}

	listNode* getNext() const {
		return _next;
	}

	listNode* getPrevious() const {
		return _previous;
	}
};

#endif //LISTNODE_HPP
