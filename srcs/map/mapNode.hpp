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
		typedef T			value_type;
		typedef	T&			reference;
		typedef const T&	const_reference;
		typedef	T*			pointer;
		typedef	const T*	const_pointer;
//		typedef	C			key_compare;

		mapNode	*_parent;
		mapNode	*_left;
		mapNode	*_right;
		bool	_isBlack;
		bool 	_nil;
		T		_data;

		explicit mapNode(value_type const& val = value_type()): _parent(NULL), _left(NULL), _right(NULL), _isBlack(false), _nil(false), _data(val) {}
		mapNode(const mapNode<T>& x) : _data(x._data), _parent(x._parent), _left(x._left), _right(x._right), _isBlack(x._isBlack), _nil(false) {
		}
		virtual ~mapNode() {};
		mapNode& operator=(const mapNode& obj) {
			if (obj == this) {
				_data = obj._data;
				_left = obj._left;
				_right = obj._right;
				_parent = obj._parent;
				_isBlack = obj._isBlack;
				_nil = obj._nil;
			}
			return *this;
		}

		mapNode* getNext() {
			mapNode<T>* curr = this;
			if (_right) {
				curr = curr->_right;
				while (curr->_left) {
					curr = curr->_left;
				}
			}
			else if (!_right) {
				if (curr->_nil) {
					return curr->_parent;
				}
				while (curr->_parent && (curr->_parent->_data.first < curr->_data.first)) {
					curr = curr->_parent;
				}
				if (curr->_parent && (curr->_parent->_data.first > curr->_data.first)) {
					return curr->_parent;
				}
			}
			return curr;
		}

		mapNode* getPrevious() {
			mapNode<T>* curr = this;
			if (_left) {
				curr = curr->_left;
				while (curr->_right && (curr->_right->_data.first > curr->_data.first)) {
					curr = curr->_right;
				}
			}
			else if (!_left) {
				if (curr->_nil) {
					return curr->_parent;
				}
				while (curr->_parent && (curr->_parent->_data.first > curr->_data.first)) {
					curr = curr->_parent;
				}
				if (curr->_parent && (curr->_parent->_data.first < curr->_data.first)) {
					return curr->_parent;
				}
			}
			return curr;
		}

		bool	operator==(const mapNode& other) {
			return (this->_data == other._data);
		}
		bool	operator!=(const mapNode& other) {
			return (this->_data != other._data);
		}
		bool	operator>(const mapNode& other) {
			return (this->_data > other._data);
		}
		bool	operator<(const mapNode& other) {
			return (this->_data < other._data);
		}
		bool 	operator<=(const mapNode& other) {
			return (this->_data <= other._data);
		}
		bool 	operator>=(const mapNode& other) {
			return (this->_data >= other._data);
		}

		void setParent(mapNode* parent) {
			_parent = parent;
		}
	};

}

#endif //MAPNODE_HPP
