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
#include <iostream>
//#include <memory>
//#include <iterator>
//#include <algorithm>
//#include <cstddef>w

# define _RED			"\x1b[31m"
# define _END			"\x1b[0m"

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
		typedef ConstBidirectionalIterator<value_type, node_pointer>	const_iterator;
		typedef RevBidirectionalIterator<value_type, node_pointer>		reverse_iterator;
		typedef ConstRevBidirectionalIterator<value_type, node_pointer>	const_reverse_iterator;

		class value_compare: public std::binary_function<value_type,value_type,bool> {
			friend class map;
		protected:
			Compare comp;
			explicit value_compare (Compare c) : comp(c) {}  // constructed with map's comparison object
		public:
			typedef bool result_type;
			typedef value_type first_argument_type;
			typedef value_type second_argument_type;
			bool operator() (const value_type& x, const value_type& y) const
			{
				return comp(x.first, y.first);
			}
		};

		key_compare		key_comp() const { return _comp; }
		value_compare	value_comp() const { return value_compare(_comp); }
		bool equal(value_type const & x, value_type const & y) const { return (!value_comp()(x, y) && !value_comp()(y, x)); }
		bool equal(key_type const & x, key_type const & y) const { return (!key_comp()(x, y) && !key_comp()(y, x)); }

	private:
		node_pointer 	_root;
		node_pointer 	_first;
		node_pointer 	_last;
		size_type		_size;
		key_compare		_comp;

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
			// Clear() + delete _first and _last
		}

		// Iterators:
		iterator begin() {return iterator(_first->_parent);}
		iterator end() {return iterator(_last);}
		const_iterator begin() const {return const_iterator(_first->_parent);}
		const_iterator end() const {return const_iterator(_last);}
		reverse_iterator rbegin() {return reverse_iterator(_last->_parent);}
		reverse_iterator rend() {return reverse_iterator(_first);}
		const_reverse_iterator rbegin() const {return const_reverse_iterator(_last->_parent);}
		const_reverse_iterator rend() const {return const_reverse_iterator(_first);}

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
				return std::make_pair(iterator(_root), true);
			}
			else {
				return insertLeaf(new_node);
			}
		}

		iterator insert (iterator position, const value_type& val) {
			iterator ret;
			node_pointer new_node = new node(val);
			node_pointer hint_node = position.getPtr();
			if (empty()) {
				insertRoot(new_node);
				return iterator(_root);
			}
			else if ((!hint_node->_right && value_comp()(val, hint_node->_data))
					|| (!hint_node->_left && value_comp()(hint_node->_data, val))) {
				ret = insertLeaf(new_node, hint_node).first;
			}
			else {
				ret = insertLeaf(new_node).first;
			}

			return ret;
		}

		template <class InputIterator>
		void insert (InputIterator first, InputIterator last,
					 typename ft::check_type<typename ft::iterator_traits<InputIterator>::iterator_category>::type* = 0) {
			while (first != last) {
				insert(*first);
				++first;
			}
		}

		iterator find (const key_type& k) {
			for (iterator it = begin(); it != end(); ++it) {
				if (equal(k, it->first))
					return it;
			}
			return end();
		}
		const_iterator find (const key_type& k) const {
			for (iterator it = begin(); it != end(); ++it) {
				if (equal(k, it->first))
					return it;
			}
			return end();
		}


		void printBT() const {
			printBT("", this->_root, true);
			std::cout << std::endl;
		}

	private:

		std::pair<iterator,bool> insertLeaf(node_pointer &x, node_pointer pos = NULL) {
			node_pointer curr;
			if (!pos) {
				curr = _root;
			}
			else {
				curr = pos;
			}
			_first->_parent->_left = NULL; // Unlink first and last trackers
			_last->_parent->_right = NULL;
			while (curr) {
				if (equal(curr->_data.first, x->_data.first)) {
					delete x;
					resetOuter();
					return std::make_pair(iterator(curr), false);
				}
				else if (key_comp()(x->_data.first, curr->_data.first)) {
					if (curr->_left) {
						curr = curr->_left;
					}
					else {
						curr->_left = x;
						x->_parent = curr;
						break;
					}
				}
				else {
					if (curr->_right) {
						curr = curr->_right;
					}
					else {
						curr->_right = x;
						x->_parent = curr;
						break;
					}
				}
			}
			balanceTree(x);
			resetOuter();
			_size++;
			return std::make_pair(iterator(x), true);
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

		void balanceTree(node_pointer &x) {
			x->_isBlack = x == _root;

			while (x != _root && !x->_parent->_isBlack && x != _last && x != _first) {
				if (tree_is_left_child(x->_parent)) {
					node_pointer y = x->_parent->_parent->_right;
					if (y != NULL && !y->_isBlack) {
						x = x->_parent;
						x->_isBlack = true;
						x = x->_parent;
						x->_isBlack = x == _root;
						y->_isBlack = true;
					}
					else {
						if (!tree_is_left_child(x)) {
							x = x->_parent;
							tree_left_rotate(x);
						}
						x = x->_parent;
						x->_isBlack = true;
						x = x->_parent;
						x->_isBlack = false;
						tree_right_rotate(x);
						break;
					}
				}
				else {
					node_pointer y = x->_parent->_parent->_left;
					if (y != NULL && !y->_isBlack) {
						x = x->_parent;
						x->_isBlack = true;
						x = x->_parent;
						x->_isBlack = x == _root;
						y->_isBlack = true;
					}
					else {
						if (tree_is_left_child(x)) {
							x = x->_parent;
							tree_right_rotate(x);
						}
						x = x->_parent;
						x->_isBlack = true;
						x = x->_parent;
						x->_isBlack = false;
						tree_left_rotate(x);
						break;
					}
				}
			}
		}

		bool tree_is_left_child(node_pointer &x)
		{
			return x == x->_parent->_left;
		}

		bool tree_is_right_child(node_pointer &x)
		{
			return x == x->_parent->_right;
		}

		//     y                               x
		//    / \     Right Rotation          /  \
		//   x   T3   - - - - - - - >        T1   y
		//  / \       < - - - - - - -            / \
		// T1  T2     Left Rotation            T2  T3

		void tree_left_rotate(node_pointer x)
		{
			node_pointer y = x->_right;
			x->_right = y->_left;
			if (x->_right != NULL)
				x->_right->setParent(x);
			y->_parent = x->_parent;
			if (x == _root)
				_root = y;
			else if (tree_is_left_child(x))
				x->_parent->_left = y;
			else
				x->_parent->_right = y;
			y->_left = x;
			x->setParent(y);
		}
		void tree_right_rotate(node_pointer x)
		{
			node_pointer y = x->_left;
			x->_left = y->_right;
			if (x->_left != NULL)
				x->_left->setParent(x);
			y->_parent = x->_parent;
			if (x == _root)
				_root = y;
			else if (tree_is_left_child(x))
				x->_parent->_left = y;
			else
				x->_parent->_right = y;
			y->_right = x;
			x->setParent(y);
		}

		void printBT(const std::string& prefix, const node_pointer trav, bool isLeft) const {
			if (trav && trav != _first && trav != _last) {
				std::cout << prefix;
				std::cout << (isLeft ? "└L─" : "├R-" );
				// print the value of the node
				if (!trav->_isBlack)
					std::cout << _RED;
				std::cout << trav->_data.first << _END << std::endl ;
				// enter the next tree level - left and right branch
				printBT( prefix + (!isLeft ? "│   " : "    "), trav->_right, false);
				printBT( prefix + (!isLeft ? "│   " : "    "), trav->_left, true);
			}
		}
	};
} // end ft

#endif //MAP_HPP
