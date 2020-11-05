/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: sam <sam@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/30 17:18:40 by sam           #+#    #+#                 */
/*   Updated: 2020/10/30 17:18:40 by sam           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include "mapNode.hpp"
//#include <memory>
//#include <iterator>
//#include <algorithm>
//#include <cstddef>

namespace ft {

	template < class Key,
			class T,
			class Compare = std::less<Key>,
			class Alloc = std::allocator<std::pair<const Key,T> >
	> class map {
	public:
		// types
		typedef Key 											key_type;
		typedef T 												mapped_type;
		typedef std::pair<const key_type, mapped_type> 			value_type;
		typedef Compare 										key_compare;
		typedef T&												reference;
		typedef const T&										const_reference;
		typedef T*												pointer;
		typedef const T*										const_pointer;
		typedef mapNode<value_type>*							node_pointer;
		typedef mapNode<value_type>								node;
		typedef ptrdiff_t										difference_type;
		typedef size_t											size_type;
		typedef BidirectionalIterator<value_type, node_pointer, Alloc> iterator;
//		typedef ConstBidirectionalIterator<value_type, node_pointer>	const_iterator;
//		typedef RevBidirectionalIterator<value_type, node_pointer>		reverse_iterator;
//		typedef ConstRevBidirectionalIterator<value_type, node_pointer>	const_reverse_iterator;
	private:
		node_pointer _root;
		node_pointer _first;
		node_pointer _last;
		size_type _size;

	public:

		// Constructors/Destructor:
		explicit map() : _root(), _size(0) {
			_last = new node;
			_first = new node;
			_last->_nil = true;
			_first->_nil = true;
			_last->_parent = _first;
			_first->_parent = _last;
		}

//	explicit map(size_type n, const value_type& val = value_type()) {
//	}
//
//	template<class InputIterator>
//	map(InputIterator first, InputIterator last) {
//
//	}
//
//	map(map const& x) {
//
//	}

		// assignment operator overload
//	map& operator=(map const& x) {
//
//	}

		virtual ~map() {
		}



		// Iterators:
		iterator begin() {
			return iterator(_first->_parent);
		}

		iterator end() {
			return iterator(_last);
		}

//		const_iterator begin() const {return const_iterator(_head->_next);}
//		const_iterator end() const {return const_iterator(_tail);}
//		reverse_iterator rbegin() {return reverse_iterator(_tail->_previous);}
//		reverse_iterator rend() {return reverse_iterator(_head);}
//		const_reverse_iterator rbegin() const {return const_reverse_iterator(_tail->_previous);}
//		const_reverse_iterator rend() const {return const_reverse_iterator(_head);}

		// Capacity:
		bool empty() const {
			if (_size == 0)
				return true;
			return false;
		}

		size_type size() const {
			return _size;
		}

		size_type max_size() const {
			return this->_allocator.max_size();
		}

		std::pair<iterator,bool> insert (const value_type& val) {
			node_pointer new_node = new node(val);
			if (empty()) {
				insertRoot(new_node);
				_size++;
				return std::make_pair(_root, true);
			}
			else {
				new_node->_isBlack = false;
				return insertLeaf(new_node);
			}
		}

	private:

		std::pair<iterator,bool> insertLeaf(const node_pointer &x) {
			node_pointer curr = _root;
			while (curr) {
				if (curr->_data.first == x->_data.first) {
					return std::make_pair(curr, false);
				}
				else if (curr->_data.first > x->_data.first) {
					if (curr->_left && curr->_left != _first) {
						curr = curr->_left;
					}
					else {
						curr->_left = x;
						x->_parent = curr;
						break;
					}
				}
				else {
					if (curr->_right && curr->_right != _last) {
						curr = curr->_right;
					}
					else {
						curr->_right = x;
						x->_parent = curr;
						break;
					}
				}
			}
			resetOuter();
			balanceTree(x);
			_size++;
			return std::make_pair(x, true);
		}

		void insertRoot(const node_pointer &x) {
			_root = x;
			_root->_isBlack = true;
			_first->_parent = _root;
			_last->_parent = _root;
			_first->_parent->_left = _first;
			_last->_parent->_right = _last;
		}

		void resetOuter() {
			node_pointer tmp_node = _root;
			while (tmp_node->_left != NULL && tmp_node->_left != _first) {
				tmp_node = tmp_node->_left;
			}
			_first->_parent = tmp_node;
			_first->_parent->_left = _first;
			tmp_node = _root;
			while (tmp_node->_right != NULL && tmp_node->_right != _last) {
				tmp_node = tmp_node->_right;
			}
			_last->_parent = tmp_node;
			_last->_parent->_right = _last;
		}

		void balanceTree(const node_pointer &x) {
			x->_isBlack = x == _root;

			if (x->_parent->_isBlack) {
				return;
			}
			// 5) If the parent of newNode is Red then check the color of parent node's sibling of newNode.
			//6) If it is Black or NULL node then make a suitable Rotation and Recolor it.
			//7) If it is Red colored node then perform Recolor and Recheck it. Repeat the same until tree becomes Red Black Tree.
		}

		bool tree_is_left_child(const node_pointer &x) _NOEXCEPT
		{
			return x == x->__parent_->__left_;
		}

	};
} // end ft

#endif //MAP_HPP
