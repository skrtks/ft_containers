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

int main() {
	ft::list<int> myIntList;
	myIntList.push_back(2);
//	myIntList.push_back(3);
	ft::list<int>::iterator myIntIt = myIntList.begin();
//	REQUIRE(*myIntIt == 1);
	(*myIntIt)--;
//	REQUIRE(*myIntIt == 2);
	std::cout << *myIntIt-- << std::endl;
	if (myIntIt == myIntList.begin())
		return 2;
//	REQUIRE(*myIntIt == 2);

	std::list<int> sIntList;
	sIntList.push_back(2);
//	sIntList.push_back(3);
	std::list<int>::iterator sIntIt = sIntList.begin();
//	REQUIRE(*sIntIt == 1);
	(*sIntIt)--;
//	REQUIRE(*sIntIt == 2);
	std::cout << *sIntIt-- << std::endl;
	if (sIntIt == sIntList.begin())
		return 1;
//	REQUIRE(*myIntIt == 2);
	return 0;
}
