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

int main ()
{
//	ft::vector<int> myIntVec;
//	myIntVec.push_back(2);
//	myIntVec.push_back(3);
//	myIntVec.push_back(4);
//	myIntVec.push_back(5);
//	myIntVec.push_back(6);
//	ft::vector<int>::iterator it = myIntVec.begin();
//	it = it + 1;
//	it + 1;
//	it = it - 1;
////	int i = *it + *it;
//	it += 3;

	ft::vector<int> myvector;

	for (int i = 0; i < 6; i++) myvector.push_back(i);

	for (int i = 0; i < 6; i++) {
		std::cout << myvector[i] << " " << i << std::endl;
	}
}
