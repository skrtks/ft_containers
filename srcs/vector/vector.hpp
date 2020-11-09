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

#include "Traits.hpp"
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
			const allocator_type& alloc = allocator_type(),
			typename ft::check_type<typename ft::iterator_traits<InputIterator>::iterator_category>::type* = 0): _allocator(alloc) {
			_capacity = last - first;
			_size = 0;
			_array = new value_type[_capacity];
			assign(first, last);
		}

		vector (const vector& x) {
			_size = 0;
			_capacity = 0;
			*this = x;
		}

		vector& operator=(const vector& x) {
			if (&x != this) {
				if (capacity()) {
					clear();
				}
				_array = new value_type[x.capacity()];
				_capacity = x.capacity();
				assign(x.begin(), x.end());
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

		void resize (size_type n, value_type val = value_type()) {
			while (_size > n) {
				pop_back();
			}
			while (_size < n) {
				push_back(val);
			}
		}

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
			while (_size > 0) {
				pop_back();
			}
		}

		reference	operator[](difference_type n) {
			return (*(_array + n));
		}

		const_reference	operator[](difference_type n) const {
			return (*(_array + n));
		}

		reference at (size_type n) {
			if (n >= _size) {
				throw (std::out_of_range("Index out of range"));
			}
			return (*(_array + n));
		}

		const_reference at (size_type n) const {
			if (n >= _size) {
				throw (std::out_of_range("Index out of range"));
			}
			return (*(_array + n));
		}

		iterator insert (iterator position, const value_type& val) {
			size_type n = position - begin();
			insert(position, 1, val);
			return (iterator(&_array[n]));
		}

		void insert (iterator position, size_type n, const value_type& val) {
			vector tmp(position, end());
			size_type old_size = _size;
			_size -= end() - position;
			if (old_size + n > _capacity) {
				reserve(old_size + n);
			}
			for (size_type i = 0; i < n; ++i) {
				push_back(val);
			}
			for (iterator it = tmp.begin(); it != tmp.end(); ++it) {
				push_back(*it);
			}
		}

		template <class InputIterator>
		void insert (iterator position, InputIterator first, InputIterator last,
					 typename ft::check_type<typename ft::iterator_traits<InputIterator>::iterator_category>::type* = 0) {
			vector tmp(position, end());
			size_type old_size = _size;
			_size -= end() - position;
			size_type n = last - first;
			if (old_size + n > _capacity) {
				reserve(old_size + n);
			}
			while (first != last) {
				push_back(*first);
				++first;
			}
			for (iterator it = tmp.begin(); it != tmp.end(); ++it) {
				push_back(*it);
			}
		}

		iterator erase (iterator position) {
			if (position == --end()) {
				pop_back();
			}
			else {
				vector tmp(position, end());
				_size -= end() - position;
				for (iterator it = tmp.begin() + 1; it != tmp.end(); ++it) {
					push_back(*it);
				}
			}
			return ++position;
		}

		iterator erase (iterator first, iterator last) {
			size_type n = last - first;
			if (last == end()) {
				_size -= n;
			}
			else {
				vector tmp(last, end());
				_size -= end() - first;
				for (iterator it = tmp.begin(); it != tmp.end(); ++it) {
					push_back(*it);
				}
			}
			return ++last;
		}

		void swap (vector& x) {
			size_type tmp;
			pointer tmpPtr;
			tmpPtr = _array;
			_array = x._array;
			x._array = tmpPtr;
			tmp = _size;
			_size = x._size;
			x._size = tmp;
			tmp = _capacity;
			_capacity = x._capacity;
			x._capacity = tmp;
		}


		pointer getArray() const {
			return _array;
		}

	private:
			pointer _array;
			size_type _size;
			size_type _capacity;
			allocator_type _allocator;
	};

	// Relational operators
	template <class value_type, class allocator_type>
	bool operator== (const vector<value_type,allocator_type>& lhs, const vector<value_type,allocator_type>& rhs) {
		if (lhs.size() != rhs.size()) {
			return false;
		}
		typename ft::vector<value_type>::iterator lhsIt = lhs.begin();
		typename ft::vector<value_type>::iterator rhsIt = rhs.begin();
		while (lhsIt != lhs.end() && rhsIt != rhs.end()) {
			if (!(*lhsIt == *rhsIt)) {
				return false;
			}
			++lhsIt;
			++rhsIt;
		}
		return true;
	}
	template<class value_type, class allocator_type>
	bool operator!=(const vector<value_type, allocator_type>& lhs, const vector<value_type, allocator_type>& rhs) {
		return !(lhs == rhs);
	}
	template<class value_type, class allocator_type>
	bool operator<(const vector<value_type, allocator_type>& lhs, const vector<value_type, allocator_type>& rhs) {
		return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}
	template<class value_type, class allocator_type>
	bool operator<=(const vector<value_type, allocator_type>& lhs, const vector<value_type, allocator_type>& rhs) {
		return !(rhs < lhs);
	}
	template<class value_type, class allocator_type>
	bool operator>(const vector<value_type, allocator_type>& lhs, const vector<value_type, allocator_type>& rhs) {
		return rhs < lhs; // Yes this is correct
	}
	template<class value_type, class allocator_type>
	bool operator>=(const vector<value_type, allocator_type>& lhs, const vector<value_type, allocator_type>& rhs) {
		return !(lhs < rhs); // Yes this is correct
	}

} // ft end

#endif //VECTOR_HPP
