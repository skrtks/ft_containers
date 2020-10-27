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

#include "Vector.hpp"
#include <list>
#include <vector>
#include <cmath>

int main ()
{
	ft::vector<int> myvector(10, 42);

	// set some content in the vector:
//	for (int i=0; i<20; i++) myvector.push_back(i);

	ft::vector<int>::iterator myIt = myvector.end();
//	myIt--;
	std::cout << "iterator val: " << *myIt << '\n';
	std::cout << "size: " << (int) myvector.size() << '\n';
	std::cout << "capacity: " << (int) myvector.capacity() << '\n';
	return 0;
}
