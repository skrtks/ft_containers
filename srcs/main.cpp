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
#include <cmath>
#include <deque>
#include <queue>
#include <stack>

int main ()
{
	std::vector<int> myvector (3,100);
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2;

	it = myvector.begin();
	it2 = myvector.end();
	std::cout << it - it2 << std::endl;
	return 0;
}
