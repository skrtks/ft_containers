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
#include "BidirectionalIterator.hpp"
#include "Traits.hpp"
#include <iostream>

# define _RED			"\x1b[31m"
# define _END			"\x1b[0m"

namespace ft {

	enum findType {
		EQUAL,
		LOWER,
		UPPER
	};

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
		typedef Alloc											allocator_type;
		typedef ptrdiff_t										difference_type;
		typedef size_t											size_type;
		typedef BidirectionalIterator<value_type, node_pointer, Alloc> iterator;
		typedef ConstBidirectionalIterator<value_type, node_pointer, Alloc>	const_iterator;
		typedef RevBidirectionalIterator<value_type, node_pointer, Alloc>		reverse_iterator;
		typedef ConstRevBidirectionalIterator<value_type, node_pointer, Alloc>	const_reverse_iterator;

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

	private:
		node_pointer 	_root;
		node_pointer 	_first;
		node_pointer 	_last;
		size_type		_size;
		key_compare		_comp;
		allocator_type 	_alloc;

	public:

		// Constructors/Destructor:
		explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
				: _root(), _size(0), _comp(comp), _alloc(alloc) {
			init_outer();
		}

		template <class InputIterator>
		map (InputIterator first, InputIterator last,
			 const key_compare& comp = key_compare(),
			 const allocator_type& alloc = allocator_type())
			 : _root(), _size(0), _comp(comp), _alloc(alloc) {
			init_outer();
			insert(first, last);
		}

		map(map const& x): _root(), _size(0) {
			init_outer();
			_alloc = x._alloc;
			_comp = x._comp;
			insert(x.begin(), x.end());
		}

		// assignment operator overload
		map& operator=(map const& x) {
			if (this != &x) {
				clear();
				_alloc = x._alloc;
				_comp = x._comp;
				insert(x.begin(), x.end());
			}
			return (*this);
		}

		virtual ~map() {
			erase(begin(), end());
			delete _last;
			delete _first;
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

		mapped_type& operator[] (const key_type& k) {
			return (*((this->insert(std::make_pair(k, mapped_type()))).first)).second;
		}

		std::pair<iterator,bool> insert (const value_type& val) {
			if (empty()) {
				insertRoot(val);
				_size++;
				return std::make_pair(iterator(_root), true);
			}
			else {
				return insertLeaf(val);
			}
		}

		iterator insert (iterator position, const value_type& val) {
			iterator ret;
			node_pointer hint_node = position.getPtr();
			if (empty()) {
				insertRoot(val);
				return iterator(_root);
			}
			else if ((!hint_node->_right && value_comp()(val, hint_node->_data))
					|| (!hint_node->_left && value_comp()(hint_node->_data, val))) {
				ret = insertLeaf(val, hint_node).first;
			}
			else {
				ret = insertLeaf(val).first;
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

		void clear() {
			erase(begin(), end());
		}

		void erase (iterator position) {
			treeRemove(position);
		}
		size_type erase (const key_type& k) {
			iterator pos;
			size_type ret = 0;
			while ((pos = find(k)) != end()) {
				treeRemove(pos);
				ret++;
			}
			return ret;
		}
		void erase (iterator first, iterator last) {
			while (first != last) {
				first = treeRemove(first);
			}
		}

		void swap (map& x) {
			itemSwap(_root, x._root);
			itemSwap(_first, x._first);
			itemSwap(_last, x._last);
			itemSwap(_size, x._size);
		}

		size_type count (const key_type& k) const {
			if (find(k) != end()) {
				return 1;
			}
			return 0;
		}

		iterator find (const key_type& k) {
			node_pointer n = recursiveFind(k, _root, EQUAL);
			return (n ? iterator(n) : end());
		}
		const_iterator find (const key_type& k) const {
			node_pointer n = recursiveFind(k, _root, EQUAL);
			return (n ? const_iterator(n) : end());
		}

		key_compare		key_comp() const { return _comp; }
		value_compare	value_comp() const { return value_compare(_comp); }

		iterator lower_bound (const key_type& k) {
			node_pointer n = recursiveFind(k, _root, LOWER);
			return (n ? iterator(n) : end());
		}

		const_iterator lower_bound (const key_type& k) const {
			node_pointer n = recursiveFind(k, _root, LOWER);
			return (n ? const_iterator(n) : end());
		}

		iterator upper_bound (const key_type& k) {
			node_pointer n = recursiveFind(k, _root, UPPER);
			return (n ? iterator(n) : end());
		}

		const_iterator upper_bound (const key_type& k) const {
			node_pointer n = recursiveFind(k, _root, UPPER);
			return (n ? const_iterator(n) : end());
		}

		std::pair<const_iterator,const_iterator> equal_range (const key_type& k) const {
			return (std::make_pair(const_iterator(lower_bound(k)), const_iterator(upper_bound(k))));
		}
		std::pair<iterator,iterator>             equal_range (const key_type& k) {
			return (std::make_pair(iterator(lower_bound(k)), iterator(upper_bound(k))));
		}

		void printBT() const {
			printBT("", this->_root, true);
			std::cout << std::endl;
		}

	private:

		void init_outer() {
			_last = new node;
			_first = new node;
			_last->_nil = true;
			_first->_nil = true;
			_last->_parent = _first;
			_first->_parent = _last;
		}

		bool equal(value_type const & x, value_type const & y) const { return (!value_comp()(x, y) && !value_comp()(y, x)); }
		bool equal(key_type const & x, key_type const & y) const { return (!key_comp()(x, y) && !key_comp()(y, x)); }

		node_pointer recursiveFind(const key_type& k, const node_pointer& x, const findType& type) const {
			if (x && !x->_nil) {
				if ((type == EQUAL && equal(x->_data.first, k)) ||
					(type == LOWER && (equal(x->_data.first, k) || key_comp()(x->_data.first, k))) ||
					(type == UPPER && key_comp()(k, x->_data.first))) {
					return x;
				}
				else if (key_comp()(k, x->_data.first)) {
					return recursiveFind(k, x->_left, type);
				}
				else {
					return recursiveFind(k, x->_right, type);
				}
			}
			return NULL;
		}

		iterator treeRemove(iterator position) {
			node_pointer x = position.getPtr();
			node_pointer y;

			++position;
			bool wasBlack = x->_isBlack;
			if (x->_nil)
				return ++position;
			unlinkOuter();
			if (x->_left == NULL && x->_right == NULL) {
				if (!x->_parent) {
					delete x;
					--_size;
					return iterator (end());
				}
				if (tree_is_left_child(x)) x->_parent->_left = NULL;
				else x->_parent->_right = NULL;
				y = x->_parent;
				delete x;
				--_size;
			}
			else {
				if (x->_left && x->_right) {
					y = treeNext(x);
					if (y->_parent) {
						tree_is_left_child(y) ? y->_parent->_left = NULL : y->_parent->_right = NULL;
					}
					y->_parent = x->_parent;
					if (x->_parent) {
						tree_is_left_child(x) ? y->_parent->_left = y : y->_parent->_right = y;
					}
					if (x->_left && x->_left != y) {
						y->_left = x->_left;
						y->_left->_parent = y;
					}
					if (x->_right && x->_right != y) {
						y->_right = x->_right;
						y->_right->_parent = y;
					}
					delete x;
					--_size;
				}
				else {
					y = x->_left ? x->_left : x->_right;
					if (x->_parent && tree_is_left_child(x)) {
						x->_parent->_left = y;
					}
					else if (x->_parent) {
						x->_parent->_right = y;
					}
					y->_parent = x->_parent;
					delete x;
					--_size;
				}
				if (!y->_parent) _root = y;
				if (wasBlack)
					balanceAfterDelete(y);
			}
			resetOuter();
			return position;
		}

		void balanceAfterDelete(node_pointer &x) {
			node_pointer w;
			while (x != _root && x->_isBlack) {
				if (tree_is_left_child(x)) {
					w = x->_parent->_right;
					if (w && !w->_isBlack) {
						w->_isBlack = true;
						w->_parent->_isBlack = false;
						tree_left_rotate(x->_parent);
						w = x->_parent->_right;
					}
					if (w && w->_left && w->_left->_isBlack
						&& w->_right && w->_right->_isBlack) {
						w->_isBlack = false;
						x = x->_parent;
					}
					else {
						if (w && w->_right && w->_right->_isBlack) {
							w->_left->_isBlack = true;
							w->_isBlack = false;
							tree_right_rotate(w);
							w = x->_parent->_right;
						}
						if (w) {
							w->_isBlack = w->_parent->_isBlack;
							x->_parent->_isBlack = true;
							if (w->_right) {
								w->_right->_isBlack = true;
							}
							tree_left_rotate(x->_parent);
							x = _root;
						}
					}
				}
				else {
					{
						w = x->_parent->_left;
						if (w && !w->_isBlack) {
							w->_isBlack = true;
							w->_parent->_isBlack = false;
							tree_right_rotate(w->_parent);
							w = x->_parent->_left;
						}
						if (w && w->_right && w->_right->_isBlack
							&& w->_left && w->_left->_isBlack) {
							w->_isBlack = false;
							x = x->_parent;
						}
						else {
							if (w && w->_left && w->_left->_isBlack) {
								w->_right->_isBlack = true;
								w->_isBlack = false;
								tree_left_rotate(w);
								w = x->_parent->_left;
							}
							if (w) {
								w->_isBlack = w->_parent->_isBlack;
								x->_parent->_isBlack = true;
								if (w->_left) {
									w->_left->_isBlack = true;
								}
								tree_right_rotate(x->_parent);
								x = _root;
							}
						}
					}
				}
			}
			x->_isBlack = true;
		}

		node_pointer treeNext(node_pointer x)
		{
			if (x->_right != NULL) {
				x = x->_right;
				while (x->_left != NULL && !x->_left->_nil)
					x = x->_left;
				return x;
			}
			while (!tree_is_left_child(x))
				x = x->_parent;
			return x->_parent;
		}

		std::pair<iterator,bool> insertLeaf(const value_type& val, node_pointer pos = NULL) {
			node_pointer curr;
			iterator ret;
			node_pointer x = new node(val);;
			if ((ret = find(x->_data.first)) != end()) {
				delete x;
				resetOuter();
				return std::make_pair(ret, false);
			}
			if (!pos) {
				curr = _root;
			}
			else {
				curr = pos;
			}
			unlinkOuter();
			while (curr) {
				if (key_comp()(x->_data.first, curr->_data.first)) {
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
			ret = iterator(x);
			balanceTree(x);
			resetOuter();
			_size++;
			return std::make_pair(ret, true);
		}

		void insertRoot(const value_type& val) {
			node_pointer x = new node(val);
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

		void unlinkOuter() {
			_first->_parent->_left = NULL; // Unlink first and last trackers
			_last->_parent->_right = NULL;
		}

		void balanceTree(node_pointer &x) {
			x->_isBlack = x == _root;

			while (x != _root && x->_parent->_parent && !x->_parent->_isBlack && x != _last && x != _first) {
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

		/*     y                               x
		    / \     Right Rotation          /  \
		   x   T3   - - - - - - - >        T1   y
		  / \       < - - - - - - -            / \
		 T1  T2     Left Rotation            T2  T3*/

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

		void printBT(const std::string& prefix, const node_pointer& trav, bool isLeft) const {
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

		template< typename S >
		void	itemSwap(S& var1, S& var2) {
			S tmpvar = var1;
			var1 = var2;
			var2 = tmpvar;
		}
	};
} // end ft

#endif //MAP_HPP
