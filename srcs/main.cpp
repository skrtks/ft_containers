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

int main()
{
	ft::list<int> first (3,100);   // three ints with a value of 100
	ft::list<int> second (5,200);  // five ints with a value of 200

	first.swap(second);

	std::cout << "first contains:";
	for (ft::list<int>::const_reverse_iterator it=first.rbegin(); it!=first.rend(); it++)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "second contains:";
	for (ft::list<int>::const_iterator it=second.begin(); it!=second.end(); it++)
		std::cout << ' ' << *it;
	std::cout << '\n';
	return 0;
}
