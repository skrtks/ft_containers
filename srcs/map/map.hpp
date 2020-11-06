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
			// Clear() + delete _first and _last
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
				return insertLeaf(new_node);
			}
		}

		void printBT() const {
			printBT("", this->_root, true);
			std::cerr << std::endl;
		}

	private:

		std::pair<iterator,bool> insertLeaf(node_pointer &x) {
			node_pointer curr = _root;

			_first->_parent->_left = NULL; // Unlink first and last trackers
			_last->_parent->_right = NULL;
			while (curr) {
				if (curr->_data.first == x->_data.first) {
					return std::make_pair(curr, false);
				}
				else if (curr->_data.first > x->_data.first) {
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
