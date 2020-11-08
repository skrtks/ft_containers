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
	ft::map<int, int> myMap;

	myMap.insert(std::make_pair(9, 9));
	myMap.insert(std::make_pair(3, 3));
	myMap.insert(std::make_pair(8, 8));
	myMap.insert(std::make_pair(0, 0));
	myMap.insert(std::make_pair(7, 7));
	myMap.insert(std::make_pair(6, 6));
	myMap.insert(std::make_pair(5, 5));
	myMap.insert(std::make_pair(4, 4));
	myMap.insert(std::make_pair(2, 2));
	myMap.insert(std::make_pair(1, 1));


	myMap.printBT();
	ft::map<int, int>::iterator it = myMap.find(3);
	myMap.erase(it);
	myMap.printBT();
//	ft::map<int, int>::iterator it = myMap.begin();
//	for (; it != myMap.end(); it++)
//		std::cout << it->first << std::endl;
//	std::cout << std::endl;
//	ft::map<int, int>::iterator it2 = myMap.end();
//	it2--;
//	for (; it2 != --myMap.begin(); it2--)
//		std::cout << it2->first << std::endl;

	return 0;
}
