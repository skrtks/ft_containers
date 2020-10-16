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
	ft::list<std::string> myList;
	std::list<std::string> sysList;
	std::string str = "Hello, world!";
	myList.push_back(str);
	sysList.push_back(str);
	myList.push_back("I'm the next King");
	sysList.push_back("I'm the next King");
	myList.push_back("I'm the next Queen");
	sysList.push_back("I'm the next Queen");

	ft::list<std::string>::iterator myIt = myList.begin();
	std::list<std::string>::iterator sysIt = sysList.begin();
	myIt++;
	sysIt++;
	std::cout << "My: " << *myIt << std::endl;
	std::cout << "Sys: " << *sysIt << std::endl;
	++myIt;
	++sysIt;
	std::cout << "My: " << myIt->data() << std::endl;
	std::cout << "Sys: " << sysIt->data() << std::endl;
	return 0;
}
