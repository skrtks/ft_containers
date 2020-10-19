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

	template <typename Iterator>
	struct is_iterator {
		typedef Iterator type;
		static const bool value = false;
	};

	template <>
	struct is_iterator<std::bidirectional_iterator_tag> {
		typedef std::bidirectional_iterator_tag type;
		static const bool value = true;
	};
}


#endif //TRAITS_HPP
