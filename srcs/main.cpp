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
#include "map.hpp"
#include "mapNode.hpp"


int main ()
{
	ft::map<int, int> myMap;

	ft::mapNode<std::pair<const int, int> >* root = new ft::mapNode<std::pair<const int, int> >(std::make_pair(5, 5));
	root->_left = new ft::mapNode<std::pair<const int, int> >(std::make_pair(3, 3));
	root->_left->_parent = root;
	root->_right = new ft::mapNode<std::pair<const int, int> >(std::make_pair(7, 7));
	root->_right->_parent = root;
	root->_left->_left = new ft::mapNode<std::pair<const int, int> >(std::make_pair(2, 2));
	root->_left->_left->_parent = root->_left;
	root->_left->_right = new ft::mapNode<std::pair<const int, int> >(std::make_pair(4, 4));
	root->_left->_right->_parent = root->_left;
	root->_right->_left = new ft::mapNode<std::pair<const int, int> >(std::make_pair(6, 6));
	root->_right->_left->_parent = root->_right;
	root->_right->_right = new ft::mapNode<std::pair<const int, int> >(std::make_pair(8, 8));
	root->_right->_right->_parent = root->_right;
	myMap.setRoot(root);

	ft::map<int, int>::iterator it = myMap.begin();
	for (; it != myMap.end(); it++)
		std::cout << it->first << std::endl;


	return 0;
}
