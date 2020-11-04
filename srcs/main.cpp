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
#include "map.hpp"
#include "mapNode.hpp"


int main ()
{
	ft::map<int, int> myMap;

	myMap.insert(std::make_pair(2, 2));
	myMap.insert(std::make_pair(1, 1));
	myMap.insert(std::make_pair(3, 3));

	ft::map<int, int>::iterator it = myMap.begin();
	for (; it != myMap.end(); it++)
		std::cout << it->first << std::endl;

	ft::map<int, int>::iterator it2 = myMap.end();
	it2--;
	for (; it2 != --myMap.begin(); it2--)
		std::cout << it2->first << std::endl;


	return 0;
}
