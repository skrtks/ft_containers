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

//#include "vector.hpp"
//#include "list.hpp"
//#include "stack.hpp"
//#include "queue.hpp"
//#include <list>
//#include <vector>
//#include <map>
//#include <cmath>
//#include <deque>
//#include <queue>
//#include <stack>
//#include <iomanip>
#include "map.hpp"
#include <iostream>
int main ()
{
	ft::map<char,int> mymap;
	ft::map<char,int>::iterator it;

	// insert some values:
	mymap.insert(std::make_pair('a', 10));
	mymap.insert(std::make_pair('b', 20));
	mymap.insert(std::make_pair('c', 30));
	mymap.insert(std::make_pair('d', 40));
	mymap.insert(std::make_pair('e', 50));
	mymap.insert(std::make_pair('f', 60));

	it=mymap.find('b');
	mymap.erase (it);                   // erasing by iterator

	mymap.erase ('c');                  // erasing by key

	it=mymap.find ('e');
	mymap.erase ( it, mymap.end() );    // erasing by range

	// show content:
	for (it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	return 0;
}
