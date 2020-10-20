/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Traits.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: skorteka <skorteka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/19 12:01:23 by skorteka      #+#    #+#                 */
/*   Updated: 2020/10/19 12:01:23 by skorteka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRAITS_HPP
#define TRAITS_HPP

namespace ft {
	template <bool b, class T = void>struct enable_if {};
	template<class T>
	struct enable_if<true, T> {
		typedef T type;
	};

//	template <class T>
//	struct is_valid
//	{
//		template <class U>
//		static char is_type(U *);
//
//		template <class X, class Y>
//		static char is_type(Y X::*);
//
//		template <class U>
//		static char is_type(U (*)());
//
//		template<class X, class Y>
//		static char is_type(ft::BidirectionalIterator<X, Y>);
//
//		static double is_type(...);
//
//		static T t;
//		enum { value = sizeof(is_type(t)) == sizeof(char) };
//		typedef T type;
//	};

	template<class T>
	struct check_it {
		typedef T type;
		enum { value = false };
	};
	template <>
	struct check_it<std::bidirectional_iterator_tag> {
		typedef std::bidirectional_iterator_tag type;
		enum { value = true };
	};

	template <>
	struct check_it<std::forward_iterator_tag> {
		typedef std::forward_iterator_tag type;
		enum { value = true };
	};

	template <>
	struct check_it<std::input_iterator_tag> {
		typedef std::input_iterator_tag type;
		enum { value = true };
	};

	template <>
	struct check_it<std::random_access_iterator_tag> {
		typedef std::random_access_iterator_tag type;
		enum { value = true };
	};

	template <>
	struct check_it<std::output_iterator_tag> {
		typedef std::output_iterator_tag type;
		enum { value = true };
	};

	template <typename Category>
	struct check_category {
		check_it<typename Category::iterator_category> ohhh;
	};

	template <class U>
	struct check_category<U *> {
		typedef U type;
		enum { value = true };
	};

	template <class X, class Y>
	struct check_category<Y X::*> {
		typedef X type;
		enum { value = true };
	};

	template <class U>
	struct check_category<U (*)()> {
		typedef U type;
		enum { value = true };
	};

//	template <typename Category>
//	struct check_category {
//		template <class U>
//		static char is_ptr(U *);
//
//		template <class X, class Y>
//		static char is_ptr(Y X::*);
//
//		template <class U>
//		static char is_ptr(U (*)());
//
//		static double is_ptr(...);
//		typedef Category type;
//		static Category t;
//		enum { value = sizeof(is_ptr(t)) == sizeof(char) };
//	};
//
//	template <>
//	struct check_category<std::bidirectional_iterator_tag> {
//		typedef std::bidirectional_iterator_tag type;
//		enum { value = true };
//	};
//
//	template <>
//	struct check_category<std::forward_iterator_tag> {
//		typedef std::forward_iterator_tag type;
//		enum { value = true };
//	};
//
//	template <>
//	struct check_category<std::input_iterator_tag> {
//		typedef std::input_iterator_tag type;
//		enum { value = true };
//	};
//
//	template <>
//	struct check_category<std::random_access_iterator_tag> {
//		typedef std::random_access_iterator_tag type;
//		enum { value = true };
//	};
//
//	template <>
//	struct check_category<std::output_iterator_tag> {
//		typedef std::output_iterator_tag type;
//		enum { value = true };
//	};
//
//	template <typename Iterator>
//	struct is_iterator: public check_category<typename Iterator::iterator_category> {
//
//	};
}

#endif //TRAITS_HPP
