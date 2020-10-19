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
	template <bool b, class T = void> struct enable_if {};
	template<class T>
	struct enable_if<true, T> {
		typedef T type;
	};

//	template <class T>
//	struct is_pointer
//	{
		template <class U>
		static char is_ptr(U *);

		template <class X, class Y>
		static char is_ptr(Y X::*);

		template <class U>
		static char is_ptr(U (*)());

		static double is_ptr(...);

//		static T t;
//		enum { value = sizeof(is_ptr(t)) == sizeof(char) };
//		typedef T type;
//	};

	template <typename Iterator>
	struct check_category {
		typedef Iterator type;
		static Iterator t;
		enum { value = sizeof(is_ptr(t)) == sizeof(char) };
	};

	template <>
	struct check_category<std::bidirectional_iterator_tag> {
		typedef std::bidirectional_iterator_tag type;
		enum { value = true };
	};

	template <>
	struct check_category<std::forward_iterator_tag> {
		typedef std::forward_iterator_tag type;
		enum { value = true };
	};

	template <>
	struct check_category<std::input_iterator_tag> {
		typedef std::input_iterator_tag type;
		enum { value = true };
	};

	template <>
	struct check_category<std::random_access_iterator_tag> {
		typedef std::random_access_iterator_tag type;
		enum { value = true };
	};

	template <>
	struct check_category<std::output_iterator_tag> {
		typedef std::output_iterator_tag type;
		enum { value = true };
	};

	template <typename Iterator>
	struct is_iterator: public check_category<Iterator> {

	};
}

#endif //TRAITS_HPP
