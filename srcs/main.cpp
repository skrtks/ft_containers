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

int main ()
{
	std::map<int, int> myMap;

	myMap.insert(std::pair<int, int>(9, 1));
	myMap.insert(std::pair<int, int>(10, 1));
	myMap.insert(std::pair<int, int>(11, 1));
	myMap.insert(std::pair<int, int>(2, 1));
	myMap.insert(std::pair<int, int>(4, 1));
	myMap.insert(std::pair<int, int>(5, 1));
	myMap.insert(std::pair<int, int>(8, 1));

	std::map<int, int>::iterator it = myMap.begin();
	for (; it != myMap.end(); it++)
		std::cout << it->first << std::endl;


	return 0;
}
