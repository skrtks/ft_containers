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
	ft::list<int> myList;
	myList.push_back(1);
	myList.push_back(2);
	myList.push_back(3);
	ft::list<int>::iterator it = myList.begin();

	ft::list<int>::iterator myIt = myList.begin();
	while (myIt != myList.end()) {
		std::cout << *myIt << std::endl;
		myIt++;
	}

	myList.pop_front();
	myIt = myList.begin();
	while (myIt != myList.end()) {
		std::cout << *myIt << std::endl;
		myIt++;
	}
	return 0;
}
