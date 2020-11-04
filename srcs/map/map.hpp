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
		typedef Key										key_type;
		typedef T										mapped_type;
		typedef	std::pair<const key_type,mapped_type>	value_type;
		typedef Compare									key_compare;
		typedef T										&reference;
		typedef const T									&const_reference;
		typedef T										*pointer;
		typedef const T									*const_pointer;
		typedef mapNode<value_type>						*node_pointer;
		typedef ptrdiff_t								difference_type;
		typedef size_t									size_type;
		typedef BidirectionalIterator<value_type, node_pointer, Alloc>			iterator;
//		typedef ConstBidirectionalIterator<value_type, node_pointer>	const_iterator;
//		typedef RevBidirectionalIterator<value_type, node_pointer>		reverse_iterator;
//		typedef ConstRevBidirectionalIterator<value_type, node_pointer>	const_reverse_iterator;
	private:
		node_pointer _root;
		size_type _size;

	public:

		// Constructors/Destructor:
		explicit map(): _root(), _size(0) {
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
			node_pointer tmp_node = _root;
			while (tmp_node->_left != NULL) {
				tmp_node = tmp_node->_left;
			}
			return iterator(tmp_node);
		}

		iterator end() {
			node_pointer tmp_node = _root;
			while (tmp_node->_right != NULL) {
				tmp_node = tmp_node->_right;
			}
			return iterator(tmp_node);
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

		size_type	max_size() const {
			return this->_allocator.max_size();
		}

//		pair<iterator,bool> insert (const value_type& val);
	public:
		void setRoot(node_pointer root) { // TODO: Remove this before pushing
			_root = root;
		}
	};

} // end ft

#endif //MAP_HPP
