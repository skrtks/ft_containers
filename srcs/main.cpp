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
#include <list>
#include <vector>
#include <cmath>
#include <deque>
#include <stack>

int main ()
{
	ft::vector<int> myvector (2,200);
	ft::vector<int> myvector2 (2,300);
	ft::stack<int, ft::vector<int> > mystack(myvector);
	ft::stack<int, ft::vector<int> > mystack2(myvector2);

	if (mystack != mystack2) {
		std::cout << "Hoi\n";
	}

	return 0;
}
