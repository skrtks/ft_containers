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
	std::list<int> mylist (2,200);
	std::queue<int, std::list<int> > myqueue(mylist);

	myqueue.push(3);

	myqueue.pop();

	return 0;
}
