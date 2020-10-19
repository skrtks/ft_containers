/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: skorteka <skorteka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/14 11:38:09 by skorteka      #+#    #+#                 */
/*   Updated: 2020/10/14 11:38:09 by skorteka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "list.hpp"
#include <list>

//template <bool, class T = void> struct enable_if {};
//template<class T>
//struct enable_if<true, T> {
//	typedef T type;
//};
//
//template <typename T>
//struct is_test {
//	static const bool value = false;
//};
//template<>
//struct is_test<std::string> {
//	static const bool value = true;
//};

//template <class InputIterator>
//void assign (InputIterator first, InputIterator last) {
//	while (first != last) {
//		push_back(*first);
//		first++;
//	}
//}
//
//void assign (size_t n, const value_type& val) {
//	for (size_t i = 0; i < n; i++) {
//		std::cout << "Assign(n, val): " << val << std::endl;
//	}
//}

int main()
{
	ft::list<int>	oneL;
	ft::list<int>	twoL;
	twoL.push_back(1);
	twoL.push_back(2);
	twoL.push_back(3);

	oneL.assign(twoL.begin(), twoL.end());
	for (ft::list<int>::iterator it = oneL.begin(); it != oneL.end(); it++) {
		std::cout << " " << *it;
	}
	std::cout << std::endl;

	oneL.assign(4, 300);
	for (ft::list<int>::iterator it = oneL.begin(); it != oneL.end(); it++) {
		std::cout << " " << *it;
	}
	std::cout << std::endl;

//	ft::list<int>	vec;
//	ft::list<int>::iterator	vit;
//	int myint[5] = {1, 2, 3, 4, 5};
//	vec.assign(myint, myint + 5);
//	for (vit = vec.begin(); vit != vec.end(); ++vit)
//		std::cout << *vit << std::endl;
	return 0;
}
