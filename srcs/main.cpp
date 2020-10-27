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

#include "Vector.hpp"
#include "list.hpp"
#include <list>
#include <vector>
#include <cmath>

int main () {
	ft::list<int> mylist;
	ft::list<int>::iterator it1,it2;
	// set some values:
	for (int i=1; i<10; ++i) mylist.push_back(i*10);
	// 10 20 30 40 50 60 70 80 90
	it1 = it2 = mylist.begin(); 		// ^^
	advance (it2,6);				// ^                 ^
	++it1;								//    ^              ^
//	REQUIRE(mylist.size() == 9);
//	REQUIRE(*it1 == 20);
//	REQUIRE(*it2 == 70);
	it1 = mylist.erase (it1);   // 10 30 40 50 60 70 80 90
	//    ^           ^
//	REQUIRE(*it1 == 30);
//	REQUIRE(*it2 == 70);
//	REQUIRE(mylist.size() == 8);
	it2 = mylist.erase (it2);	// 10 30 40 50 60 80 90
	//    ^           ^
	++it1;						//       ^        ^
	--it2;						//       ^     ^
//	REQUIRE(*it1 == 40);
//	REQUIRE(*it2 == 60);
//	REQUIRE(mylist.size() == 7);
	it1 = mylist.erase (it1,it2);		// 10 30 60 80 90
	//       ^
//	REQUIRE(*it1 == 60);
//	REQUIRE(*it2 == 60);
//	REQUIRE(mylist.size() == 5);
	return 0;
}
