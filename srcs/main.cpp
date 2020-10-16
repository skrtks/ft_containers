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
	{
		std::list<int> sysList;
		std::list<int>::iterator sysIt = sysList.begin();
		std::cout << "Sys: " << *sysIt << std::endl;
		*sysIt = 5;
		std::cout << "Sys: " << *sysIt << std::endl;
	}

	{
		ft::list<int> myList;
		ft::list<int>::iterator myIt = myList.begin();
		std::cout << "My: " << *myIt << std::endl;
		*myIt++ = 5;
		myIt--;
		std::cout << "My: " << *myIt << std::endl;
	}
	return 0;
}
