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

// comparison, not case sensitive.
bool compare_nocase (std::list<std::string>::iterator first, std::list<std::string>::iterator second)
{
	(void)first;
	(void)false;
	return false;
}

int main ()
{
	std::list<std::string> mylist;
	std::list<std::string>::iterator it;
	mylist.push_back ("one");
	mylist.push_back ("two");
	mylist.push_back ("Three");

	mylist.sort();

	std::cout << "mylist contains:";
	for (it=mylist.begin(); it!=mylist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	mylist.sort(compare_nocase);

	std::cout << "mylist contains:";
	for (it=mylist.begin(); it!=mylist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	return 0;
}
