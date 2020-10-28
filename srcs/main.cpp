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
	std::vector<int> myvector (3,100);
	std::vector<int>::iterator it;

	it = myvector.begin();
	it = myvector.insert ( it , 200 );
	// myvector contains: 200 100 100 100
	std::cout << "Size:" << myvector.size() << " Capacity: " << myvector.capacity() << '\n';

	myvector.insert (it,2,300);
	// myvector contains: 300 300 200 100 100 100
	std::cout << "Size:" << myvector.size() << " Capacity: " << myvector.capacity() << '\n';

	// "it" no longer valid, get a new one:
	it = myvector.begin();

	std::vector<int> anothervector (2,400);
	myvector.insert (it+2,anothervector.begin(),anothervector.end());
	std::cout << "Size:" << myvector.size() << " Capacity: " << myvector.capacity() << '\n';

	int myarray [] = { 501,502,503 };
	myvector.insert (myvector.begin(), myarray, myarray+3);
	std::cout << "Size:" << myvector.size() << " Capacity: " << myvector.capacity() << '\n';

	std::cout << "myvector contains:";
	for (it=myvector.begin(); it<myvector.end(); it++)
		std::cout << ' ' << *it;
	std::cout << '\n';
	// Size:4 Capacity: 6
	// Size:6 Capacity: 6
	// Size:8 Capacity: 12
	// Size:11 Capacity: 12
	// myvector contains: 501 502 503 300 300 400 400 200 100 100 100
	return 0;
}
