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

#include "vector.hpp"
#include "list.hpp"
#include "stack.hpp"
#include "queue.hpp"
#include <list>
#include <vector>
#include <map>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <iomanip>
#include "map.hpp"
#include "mapNode.hpp"

int main ()
{
	ft::map<char,int> mymap;

	// first insert function version (single parameter):
	mymap.insert ( std::pair<char,int>('a',100) );
	mymap.insert ( std::pair<char,int>('z',200) );

	std::pair<ft::map<char,int>::iterator,bool> ret;
	ret = mymap.insert ( std::pair<char,int>('z',500) );
	if (ret.second==false) {
		std::cout << "element 'z' already existed";
		std::cout << " with a value of " << ret.first->second << '\n';
	}

	// second insert function version (with hint position):
	ft::map<char,int>::iterator it = mymap.begin();
	mymap.insert (it, std::pair<char,int>('b',300));  // max efficiency inserting
	mymap.insert (it, std::pair<char,int>('c',400));	  // no max efficiency inserting
//	mymap.insert (std::pair<char,int>('b',300));
//	mymap.insert (std::pair<char,int>('c',400));

	// third insert function version (range insertion):
	ft::map<char,int> anothermap;
	anothermap.insert(mymap.begin(), mymap.end());

	// showing contents:
	mymap.printBT();
	std::cout << "mymap contains:\n";
	for (it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
	mymap.printBT();
	std::cout << "anothermap contains:\n";
	for (it=anothermap.begin(); it!=anothermap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	// element 'z' already existed with a value of 200
	// mymap contains:
	// a => 100
	// b => 300
	// c => 400
	// z => 200
	// anothermap contains:
	// a => 100
	// b => 300
	return 0;
}
