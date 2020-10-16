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

#ifndef NODE_HPP
#define NODE_HPP

template <class T>
class Node {
public:
	Node	*_next;
	Node	*_previous;
	T		*_data;

//	explicit ListNode(const T &obj): _next(0), _previous(0), _data(new T(obj)) {}
	explicit Node(): _next(NULL), _previous(NULL), _data(NULL) {}
	explicit Node(T element): _next(NULL), _previous(NULL), _data(new T(element)) {}
	virtual ~Node() {};
	Node& operator=(const Node& obj) {
		if (&obj != this) {
			delete _data;
			_data = new T(obj._data);
			_next = obj._next;
			_previous = obj._previous;
		}
	}
};

#endif //NODE_HPP
