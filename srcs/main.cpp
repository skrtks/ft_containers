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
#include <map>
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

	mymap['x'] = 100;
	mymap['y'] = 200;
	mymap['z'] = 300;

	// show content:
	ft::map<char,int>::iterator it;
	for (it = mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	std::cout << mymap['z'] << "!!!!!!!!!\n";
	return 0;
}
