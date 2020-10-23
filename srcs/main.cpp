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
	std::list<int> mylist;

	for (int i=1; i<10; ++i) mylist.push_back(i);

	mylist.reverse();

	std::cout << "mylist contains:";
	for (std::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
		std::cout << ' ' << *it;

	std::cout << '\n';

	return 0;
}
