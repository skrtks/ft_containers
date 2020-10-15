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
class ListNode {
	ListNode	*_next;
	ListNode	*_previous;
	T			*_data;
public:
	ListNode(): _next(0), _previous(0), _data(0) {}
//	explicit ListNode(const T &obj): _next(0), _previous(0), _data(new T(obj)) {}
	explicit ListNode(T element): _next(0), _previous(0), _data(new T(element)) {}
	virtual ~ListNode() {};
	ListNode& operator=(const ListNode& obj) {
		if (&obj != this) {
			delete _data;
			_data = new T(obj._data);
			_next = obj._next;
			_previous = obj._previous;
		}
	}
	ListNode* getNext() const {
		return _next;
	}

	ListNode* getPrevious() const {
		return _previous;
	}

	T* getData() const {
		return _data;
	}

	void setNext(ListNode* next) {
		_next = next;
	}

	void setPrevious(ListNode* previous) {
		_previous = previous;
	}

	void setData(T* data) {
		_data = data;
	}
};

#endif //LISTNODE_HPP
