/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Vector.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: sam <sam@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 13:43:49 by sam           #+#    #+#                 */
/*   Updated: 2020/10/26 13:43:49 by sam           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <memory>
#include <iterator>
#include "Traits.hpp"
#include <algorithm>
#include <cstddef>
#include "RandomAccessIterator.hpp"

namespace ft {

	template<class T, class Alloc = std::allocator<T> >
	class vector {
	public:
		// types
		typedef T value_type;
		typedef Alloc allocator_type;
		typedef T& reference;
		typedef const T& const_reference;
		typedef T* pointer;
		typedef const T* const_pointer;
		typedef ptrdiff_t difference_type;
		typedef size_t size_type;
		typedef RandomAccessIterator<value_type> iterator;
//		typedef ConstBidirectionalIterator<value_type> const_iterator;
//		typedef RevBidirectionalIterator<value_type> reverse_iterator;
//		typedef ConstRevBidirectionalIterator<value_type> const_reverse_iterator;

		// Constructors & destructor
		explicit vector (const allocator_type& alloc = allocator_type()): _allocator(alloc) {
			_array = NULL;
			_size = 0;
			_capacity = 0;
		}

		explicit vector (size_type n, const value_type& val = value_type(),
						 const allocator_type& alloc = allocator_type()): _allocator(alloc) {
			_array = new value_type[n]();
			for (size_type i = 0; i < n; ++i) {
				_array[i] = val;
			}
			_size = n;
			_capacity = n;
		}

//		template <class InputIterator>
//		vector (InputIterator first, InputIterator last,
//				const allocator_type& alloc = allocator_type()): _allocator(alloc) {
//
//		}

//		vector (const vector& x): _allocator(alloc) {
//
//		}

		virtual ~vector() {
			delete[] _array;
		}

		// Capacity:
		size_type size() const {
			return _size;
		}

		size_type max_size() const {
			return this->_allocator.max_size();
		}

	//	void resize (size_type n, value_type val = value_type()) {
	//
	//	}

		size_type capacity() const {
			return _capacity;
		}

		bool empty() const {
			return _size == 0;
		}

//		void reserve (size_type n) {
//
//		}

//		Iterators:
		iterator begin() {return iterator(_array);}
		iterator end() {return iterator(&_array[_size]);}
//		const_iterator begin() const {return const_iterator(_head->_next);}
//		const_iterator end() const {return const_iterator(_tail);}
//		reverse_iterator rbegin() {return reverse_iterator(_tail->_previous);}
//		reverse_iterator rend() {return reverse_iterator(_head);}
//		const_reverse_iterator rbegin() const {return const_reverse_iterator(_tail->_previous);}
//		const_reverse_iterator rend() const {return const_reverse_iterator(_head);}

	private:
			pointer _array;
			size_type _size;
			size_type _capacity;
			allocator_type _allocator;
		};

} // ft end

#endif //VECTOR_HPP
