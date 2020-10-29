/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RandomAccessIterator.hpp                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: skorteka <skorteka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 14:29:45 by skorteka      #+#    #+#                 */
/*   Updated: 2020/10/29 14:29:45 by skorteka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOMACCESSITERATOR_HPP
#define RANDOMACCESSITERATOR_HPP

#include <algorithm>

namespace ft {

	template<typename T, class Category = std::random_access_iterator_tag>
	class RandomAccessIterator {
	public:
		typedef T value_type;
		typedef value_type& reference;
		typedef value_type* pointer;
		typedef size_t size_type;
		typedef ptrdiff_t difference_type;
		typedef Category iterator_category;
		typedef RandomAccessIterator self_type;
	protected:
		pointer _ptr;
	public:
		RandomAccessIterator() : _ptr(NULL) {
		}

		explicit RandomAccessIterator(pointer node) : _ptr(node) {
		}

		RandomAccessIterator(const RandomAccessIterator& obj) {
			*this = obj;
		}

		RandomAccessIterator& operator=(const RandomAccessIterator& obj) {
			if (&obj != this) {
				_ptr = obj._ptr;
			}
			return *this;
		}

		virtual ~RandomAccessIterator() {
		}

		bool operator==(const RandomAccessIterator& obj) {
			return (_ptr == obj._ptr);
		}

		bool operator!=(const RandomAccessIterator& obj) {
			return (_ptr != obj._ptr);
		}

		reference operator*() {
			return *_ptr;
		}

		pointer operator->() {
			return *(&(_ptr));
		}

		RandomAccessIterator operator++(int) { // Overload postfix ++
			RandomAccessIterator ret(*this);
			_ptr++;
			return ret;
		}

		RandomAccessIterator& operator++() { // Overload prefix ++
			_ptr++;
			return *this;
		}

		RandomAccessIterator operator+(difference_type n) {
			RandomAccessIterator ret(*this);
			ret._ptr += n;
			return ret;
		}

		RandomAccessIterator operator+=(difference_type n) {
			_ptr += n;
			return *this;
		}

		RandomAccessIterator operator--(int) { // Overload postfix -
			RandomAccessIterator ret(*this);
			_ptr--;
			return ret;
		}

		RandomAccessIterator& operator--() { // Overload prefix -
			_ptr--;
			return *this;
		}

		RandomAccessIterator operator-(difference_type n) {
			RandomAccessIterator ret(*this);
			ret._ptr -= n;
			return ret;
		}

		int operator-(RandomAccessIterator it) {
			int ret;
			ret = _ptr - it.getPtr();
			return ret;
		}

		RandomAccessIterator operator-=(difference_type n) {
			_ptr -= n;
			return *this;
		}

		bool operator>=(const RandomAccessIterator& obj) {
			return (_ptr >= obj._ptr);
		}

		bool operator<=(const RandomAccessIterator& obj) {
			return (_ptr <= obj._ptr);
		}

		bool operator>(const RandomAccessIterator& obj) {
			return (_ptr > obj._ptr);
		}

		bool operator<(const RandomAccessIterator& obj) {
			return (_ptr < obj._ptr);
		}

		reference	operator[](difference_type n) {
			return (*(_ptr + n));
		}

		pointer getPtr() const {
			return _ptr;
		}
	};

	template<typename T, class Category = std::random_access_iterator_tag>
	class ConstRandomAccessIterator: public RandomAccessIterator<T> {
	public:
		typedef T value_type;
		typedef value_type& reference;
		typedef value_type* pointer;
		typedef const value_type& const_reference;
		typedef const value_type* const_pointer;
		typedef size_t size_type;
		typedef ptrdiff_t difference_type;
		typedef Category iterator_category;
		typedef ConstRandomAccessIterator self_type;

		ConstRandomAccessIterator() : RandomAccessIterator<T>(NULL) {
		}

		explicit ConstRandomAccessIterator(pointer node) : RandomAccessIterator<T>(node) {
		}

		ConstRandomAccessIterator(const ConstRandomAccessIterator& obj) {
			*this = obj;
		}

		ConstRandomAccessIterator(const RandomAccessIterator<T>& obj) {
			*this = obj;
		}

		ConstRandomAccessIterator& operator=(const ConstRandomAccessIterator& obj) {
			if (&obj != this) {
				this->_ptr = obj.getPtr();
			}
			return *this;
		}

		ConstRandomAccessIterator& operator=(const RandomAccessIterator<T>& obj) {
			if (&obj != this) {
				this->_ptr = obj.getPtr();
			}
			return *this;
		}

		virtual ~ConstRandomAccessIterator() {
		}

		const_reference operator*() {
			return *this->_ptr;
		}

		const_pointer operator->() {
			return *(&(this->_ptr));
		}

		const_reference	operator[](difference_type n) {
			return (*(this->_ptr + n));
		}
	};

	template<typename T, class Category = std::random_access_iterator_tag>
	class RevRandomAccessIterator {
	public:
		typedef T value_type;
		typedef value_type& reference;
		typedef value_type* pointer;
		typedef size_t size_type;
		typedef ptrdiff_t difference_type;
		typedef Category iterator_category;
		typedef RevRandomAccessIterator self_type;
	protected:
		pointer _ptr;
	public:
		RevRandomAccessIterator() : _ptr(NULL) {
		}

		explicit RevRandomAccessIterator(pointer node) : _ptr(node) {
		}

		RevRandomAccessIterator(const RevRandomAccessIterator& obj) {
			*this = obj;
		}

		RevRandomAccessIterator& operator=(const RevRandomAccessIterator& obj) {
			if (&obj != this) {
				_ptr = obj._ptr;
			}
			return *this;
		}

		virtual ~RevRandomAccessIterator() {
		}

		bool operator==(const RevRandomAccessIterator& obj) {
			return (_ptr == obj._ptr);
		}

		bool operator!=(const RevRandomAccessIterator& obj) {
			return (_ptr != obj._ptr);
		}

		reference operator*() {
			return *_ptr;
		}

		pointer operator->() {
			return *(&(_ptr));
		}

		RevRandomAccessIterator operator++(int) { // Overload postfix ++
			RevRandomAccessIterator ret(*this);
			_ptr--;
			return ret;
		}

		RevRandomAccessIterator& operator++() { // Overload prefix ++
			_ptr--;
			return *this;
		}

		RevRandomAccessIterator operator+(difference_type n) {
			RevRandomAccessIterator ret(*this);
			ret._ptr -= n;
			return ret;
		}

		RevRandomAccessIterator operator+=(difference_type n) {
			_ptr -= n;
			return _ptr;
		}

		RevRandomAccessIterator operator--(int) { // Overload postfix -
			RevRandomAccessIterator ret(*this);
			_ptr++;
			return ret;
		}

		RevRandomAccessIterator& operator--() { // Overload prefix -
			_ptr++;
			return *this;
		}

		RevRandomAccessIterator operator-(difference_type n) {
			RevRandomAccessIterator ret(*this);
			ret._ptr += n;
			return ret;
		}

		RevRandomAccessIterator operator-=(difference_type n) {
			_ptr += n;
			return _ptr;
		}

		bool operator>=(const RevRandomAccessIterator& obj) {
			return (_ptr >= obj._ptr);
		}

		bool operator<=(const RevRandomAccessIterator& obj) {
			return (_ptr <= obj._ptr);
		}

		bool operator>(const RevRandomAccessIterator& obj) {
			return (_ptr > obj._ptr);
		}

		bool operator<(const RevRandomAccessIterator& obj) {
			return (_ptr < obj._ptr);
		}

		reference	operator[](difference_type n) {
			return (*(_ptr + n));
		}

		pointer getPtr() const {
			return _ptr;
		}
	};

	template<typename T, class Category = std::random_access_iterator_tag>
	class ConstRevRandomAccessIterator: public RevRandomAccessIterator<T> {
	public:
		typedef T value_type;
		typedef value_type& reference;
		typedef value_type* pointer;
		typedef const value_type& const_reference;
		typedef const value_type* const_pointer;
		typedef size_t size_type;
		typedef ptrdiff_t difference_type;
		typedef Category iterator_category;
		typedef ConstRevRandomAccessIterator self_type;

		ConstRevRandomAccessIterator() : RevRandomAccessIterator<T>(NULL) {
		}

		explicit ConstRevRandomAccessIterator(pointer node) : RevRandomAccessIterator<T>(node) {
		}

		ConstRevRandomAccessIterator(const ConstRevRandomAccessIterator& obj) {
			*this = obj;
		}

		ConstRevRandomAccessIterator(const RevRandomAccessIterator<T>& obj) {
			*this = obj;
		}

		ConstRevRandomAccessIterator& operator=(const ConstRevRandomAccessIterator& obj) {
			if (&obj != this) {
				this->_ptr = obj.getPtr();
			}
			return *this;
		}

		ConstRevRandomAccessIterator& operator=(const RevRandomAccessIterator<T>& obj) {
			if (&obj != this) {
				this->_ptr = obj.getPtr();
			}
			return *this;
		}

		virtual ~ConstRevRandomAccessIterator() {
		}

		const_reference operator*() {
			return *this->_ptr;
		}

		const_pointer operator->() {
			return *(&(this->_ptr));
		}

		const_reference	operator[](difference_type n) {
			return (*(this->_ptr + n));
		}
	};

}

#endif //RANDOMACCESSITERATOR_HPP
