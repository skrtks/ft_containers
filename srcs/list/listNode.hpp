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

template <class T>
class listNode {
public:
	listNode	*_next;
	listNode	*_previous;
	T		_data;

//	explicit ListNode(const T &obj): _next(0), _previous(0), _data(new T(obj)) {}
	explicit listNode(): _next(NULL), _previous(NULL), _data(T()) {}
	explicit listNode(T element): _next(NULL), _previous(NULL), _data(T(element)) {}
	virtual ~listNode() {};
	listNode& operator=(const listNode& obj) {
		_data = obj._data;
		_next = obj._next;
		_previous = obj._previous;
		return *this;
	}
};

#endif //LISTNODE_HPP
