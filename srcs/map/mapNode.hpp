/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mapNode.hpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sam <sam@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/30 17:19:04 by sam           #+#    #+#                 */
/*   Updated: 2020/10/30 17:19:04 by sam           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPNODE_HPP
#define MAPNODE_HPP

#include "stack.hpp"

namespace ft {

	template <class T>
	class mapNode {
	public:
		static ft::stack<mapNode<T>* > _itStack;
		mapNode	*_parent;
		mapNode	*_left;
		mapNode	*_right;
		bool	_isBlack;
		T		_data;

		explicit mapNode(): _parent(NULL), _left(NULL), _right(NULL), _isBlack(false), _data(T()) {}
		explicit mapNode(T element): _parent(NULL), _left(NULL), _right(NULL), _isBlack(false), _data(T(element)) {}
		mapNode(const mapNode<T>& x) : _data(x._data), _parent(x._parent), _left(x._left), _right(x._right), _isBlack(x._isBlack) {
		}
		virtual ~mapNode() {};
		mapNode& operator=(const mapNode& obj) {
			_data = obj._data;
			_left = obj._left;
			_right = obj._right;
			_parent = obj._parent;
			_isBlack = obj._isBlack;
			return *this;
		}

		mapNode* getNext() {
			mapNode<T> *curr = _itStack.top()->_right;
			_itStack.pop();
			while (curr) {
				_itStack.push(curr);
				curr = curr->_left;
			}
			return _itStack.top();
		}
//
//		mapNode* getPrevious() const {
//			return NULL;
//		}
	};

	template <class T>
	ft::stack<mapNode<T>* > mapNode<T>::_itStack;
}

#endif //MAPNODE_HPP
