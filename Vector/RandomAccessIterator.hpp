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
			return _ptr;
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

		RandomAccessIterator operator-=(difference_type n) {
			_ptr -= n;
			return _ptr;
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

}

#endif //RANDOMACCESSITERATOR_HPP
