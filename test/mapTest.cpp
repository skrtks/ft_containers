/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mapTest.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sam <sam@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/01 11:14:55 by sam           #+#    #+#                 */
/*   Updated: 2020/11/01 11:14:55 by sam           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Catch2.h"
#include "map.hpp"

TEST_CASE("Map: Insert + empty + size", "[Map]") {
	ft::map<char,int> mymap;
	REQUIRE(mymap.empty() == true);
	// first insert function version (single parameter):
	mymap.insert ( std::pair<char,int>('a',100) );
	mymap.insert ( std::pair<char,int>('z',200) );

	std::pair<ft::map<char,int>::iterator,bool> ret;
	ret = mymap.insert ( std::pair<char,int>('z',500) );
	REQUIRE(ret.second == false);

	// second insert function version (with hint position):
	ft::map<char,int>::iterator it = mymap.begin();
	mymap.insert (it, std::pair<char,int>('b',300));  // max efficiency inserting
	mymap.insert (it, std::pair<char,int>('c',400));	  // no max efficiency inserting
	REQUIRE(mymap.size() == 4);

	// third insert function version (range insertion):
	ft::map<char,int> anothermap;
	anothermap.insert(mymap.begin(), mymap.end());
	REQUIRE(mymap.size() == 4);
}

TEST_CASE("Map: Find", "[Map]") {
	ft::map<char,int> mymap;
	// first insert function version (single parameter):
	mymap.insert ( std::pair<char,int>('a',100) );
	mymap.insert ( std::pair<char,int>('z',200) );

	// second insert function version (with hint position):
	ft::map<char,int>::iterator it;
	it = mymap.find('a');
	bool res = it == mymap.begin();
	REQUIRE(res == true);
	it = mymap.find('x');
	res = it == mymap.end();
	REQUIRE(res == true);
}