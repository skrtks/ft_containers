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
		ft::list<int> myList;
		myList.push_back(1);
		ft::list<int>::iterator myIt = myList.begin();
		std::cout << "My: " << *myIt << std::endl;
		*myIt++;
		std::cout << "My: " << *myIt << std::endl;
	}

	{
		std::list<int> sysList;
		sysList.push_back(1);
		std::list<int>::iterator sysIt = sysList.begin();
		std::cout << "Sys: " << *sysIt << std::endl;
		*sysIt++;
		std::cout << "Sys: " << *sysIt << std::endl;
	}
	return 0;
}
