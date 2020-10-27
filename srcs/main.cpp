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
#include "list.hpp"
#include <list>
#include <vector>
#include <cmath>

int main () {
	ft::vector<int> myvector;

	std::cout << "size: " << (int) myvector.size() << '\n';
	std::cout << "capacity: " << (int) myvector.capacity() << '\n';
	for (int i = 0; i < 25; ++i) {
		// set some content in the vector:
		myvector.push_back(i);

		std::cout << "size: " << (int) myvector.size() << '\n';
		std::cout << "capacity: " << (int) myvector.capacity() << '\n';
	}

	ft::vector<int>::iterator first = myvector.begin();
	ft::vector<int>::iterator last = myvector.end();
	int i =  (last - first);
	std::cout << i << std::endl;


	ft::vector<int> assignedV(first, last);
	first = assignedV.begin();
	last = assignedV.end();
	while (first != last) {
		std::cout << *first << std::endl;
		first++;
	}
	return 0;
}
