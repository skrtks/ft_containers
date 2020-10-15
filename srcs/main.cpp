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

int main() {
	std::cout << "Hello, World!" << std::endl;
	ft::list<std::string> testlist;
	std::string str = "Hello, world!";
	testlist.push_back(str);
	testlist.push_back("I'm the next King");

	ft::list<std::string>::iterator it = testlist.begin();
	it++;
	return 0;
}
