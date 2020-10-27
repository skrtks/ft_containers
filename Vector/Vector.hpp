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
		typedef ConstRandomAccessIterator<value_type> const_iterator;
		typedef RevRandomAccessIterator<value_type> reverse_iterator;
		typedef ConstRevRandomAccessIterator<value_type> const_reverse_iterator;

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

		template <class InputIterator>
		vector (InputIterator first, InputIterator last,
			const allocator_type& alloc = allocator_type()): _allocator(alloc) {
			_capacity = last - first;
			_size = 0;
			_array = new value_type[_capacity];
			assign(first, last);
		}

		vector (const vector& x) {
			*this = x;
		}

		vector& operator=(const vector& x) {
			if (&x != this) {
				if (capacity()) {
					clear();
				}
				_array = x.getPtr();
			}
			return *this;
		}

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

		void reserve (size_type n) {
			if (n > _capacity) {
				_capacity = (_capacity == 0 ? 1 : _capacity * 2);
				pointer tmp = new value_type[_capacity];
				for (size_type i = 0; i < _size; i++)
					tmp[i] = _array[i];
				delete[] _array;
				_array = tmp;
			}
		}

		reference       front()       {return _array[0];}
		const_reference front() const {return _array[0];}
		reference       back()        {return _array[_size - 1];}
		const_reference back()  const {return _array[_size - 1];}

//		Iterators:
		iterator begin() {return iterator(_array);}
		iterator end() {return iterator(&_array[_size]);}
		const_iterator begin() const {return const_iterator(_array);}
		const_iterator end() const {return const_iterator(&_array[_size]);}
		reverse_iterator rbegin() {return reverse_iterator(&_array[_size - 1]);}
		reverse_iterator rend() {
			pointer ret = _array;
			return reverse_iterator(--ret);
		}
		const_reverse_iterator rbegin() const {return const_reverse_iterator(&_array[_size - 1]);}
		const_reverse_iterator rend() const {
			pointer ret = _array;
			return reverse_iterator(--ret);
		}

		template<class InputIterator>
		void assign(InputIterator first, InputIterator last,
					typename ft::check_type<typename ft::iterator_traits<InputIterator>::iterator_category>::type* = 0) {
			clear();
			while (first != last) {
				push_back(*first);
				++first;
			}
		}

		void assign(size_type n, const value_type& val) {
			clear();
			for (size_type i = 0; i < n; i++) {
				push_back(val);
			}
		}

		void push_back (const value_type& val) {
			if (_size == _capacity) {
				reserve(_size + 1);
			}
			++_size;
			back() = val;
		}

		void	pop_back() {
			_size--;
		}

		void	clear() {
			while (_size)
				pop_back();
		}

	private:
			pointer _array;
			size_type _size;
			size_type _capacity;
			allocator_type _allocator;
		};

} // ft end

#endif //VECTOR_HPP
