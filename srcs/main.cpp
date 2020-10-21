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
#include <vector>
#include <cmath>

int main ()
{
	std::list<int> mylist1, mylist2;
	std::list<int>::iterator it;
	std::list<int>::iterator ptrIt;

	// set some initial values:
	for (int i = 1; i <= 4; ++i)
		mylist1.push_back(i);      // mylist1: 1 2 3 4
	for (int i = 1; i <= 3; ++i)
		mylist2.push_back(i * 10);   // mylist2: 10 20 30

	it = mylist1.begin();
	++it;                         // points to 2

	// Save the ptr to _data of 1st element in L2
	ptrIt = mylist2.begin();
	int* ptr = &(*ptrIt);

	mylist1.splice(it, mylist2);
	// mylist1: 1 10 20 30 2 3 4
	// mylist2 (empty)

	// Get ptr to _data of the second element in L1 (10 from L2)
	ptrIt = mylist1.begin();
	ptrIt++;
	int* ptr2 = &(*ptrIt);
	// ptr and ptr2 should be the same because the element was moved without destructing it
	if (ptr == ptr2) {
		std::cout << "Passed \n";
	}
	else {
		std::cout << "Failed \n";
	}
	return 0;
}
