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

template <class T>
struct is_pointer
{
	template <class U>
	static char is_ptr(U *);

	template <class X, class Y>
	static char is_ptr(Y X::*);

	template <class U>
	static char is_ptr(U (*)());

	static double is_ptr(...);

	static T t;
	enum { value = sizeof(is_ptr(t)) == sizeof(char) };
};

struct Foo {
	int bar;
};

int main(void)
{
//	typedef int * IntPtr;
	typedef int Foo::* FooMemberPtr;
	typedef int (*FuncPtr)();

	printf("%d\n",is_pointer<int>::value);        // prints 1
	printf("%d\n",is_pointer<FooMemberPtr>::value);  // prints 1
	printf("%d\n",is_pointer<FuncPtr>::value);       // prints 1
}

//int main() {
//	ft::list<int> myList;
//	ft::list<int> stringList;
//	myList.push_back(1);
//	myList.push_back(2);
//	myList.push_back(3);
//
//	stringList.assign(myList.begin(), myList.end());
//	for (ft::list<int>::iterator it = stringList.begin(); it != stringList.end(); it++) {
//		std::cout << " " << *it;
//	}
//	std::cout << std::endl;
//
////	stringList.assign(4, 40);
////	for (ft::list<int>::iterator it = stringList.begin(); it != stringList.end(); it++) {
////		std::cout << " " << *it;
////	}
////	std::cout << std::endl;
//	return 0;
//}
