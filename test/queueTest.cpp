/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   queueTest.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: skorteka <skorteka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 13:40:18 by skorteka      #+#    #+#                 */
/*   Updated: 2020/10/29 13:40:18 by skorteka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Catch2.h"

#include "vector.hpp"
#include "list.hpp"
#include "queue.hpp"
#include <list>
#include <vector>
#include <cmath>
#include <deque>
#include <stack>

TEST_CASE("Queue: Constructor", "[Queue]") {
	std::deque<int> mydeque (3,100);          // deque with 3 elements
	ft::vector<int> myvector (2,200);        // vector with 2 elements

	ft::queue<int> first;                    // empty queue
	ft::queue<int> second (mydeque);         // queue initialized to copy of deque

	ft::queue<int,ft::vector<int> > third;  // empty queue using vector
	ft::queue<int,ft::vector<int> > fourth (myvector);
}

TEST_CASE("Queue: Size() + Empty()", "[Queue]") {
	std::deque<int> mydeque (3,100);          // deque with 3 elements
	ft::vector<int> myvector (2,200);        // vector with 2 elements

	ft::queue<int> first;                    // empty queue
	ft::queue<int> second (mydeque);         // queue initialized to copy of deque

	ft::queue<int,ft::vector<int> > third;  // empty queue using vector
	ft::queue<int,ft::vector<int> > fourth (myvector);

	REQUIRE(first.empty() == true);
	REQUIRE(second.size() == 3);
	REQUIRE(third.empty() == true);
	REQUIRE(fourth.size() == 2);
}

TEST_CASE("Queue: Back()", "[Queue]") {
	ft::vector<int> myvector;

	// set some initial content:
	for (int i=1;i<6;i++) myvector.push_back(i);
	ft::queue<int,ft::vector<int> > myqueue (myvector);
	myqueue.back() += 5;
	REQUIRE(myqueue.back() == 10);
}

TEST_CASE("Queue: Front()", "[Queue]") {
	ft::vector<int> myvector;

	// set some initial content:
	for (int i=1;i<6;i++) myvector.push_back(i);
	ft::queue<int,ft::vector<int> > myqueue (myvector);
	myqueue.front() += 5;
	REQUIRE(myqueue.front() == 6);
}

TEST_CASE("Queue: Push() + Pop()", "[Queue]") {
	ft::queue<int> myqueue;

	for (int i=0; i<5; ++i) myqueue.push(i);
	int i = 0;
	while (!myqueue.empty())
	{
		REQUIRE(myqueue.front() == i);
		myqueue.pop();
		i++;
	}
}

TEST_CASE("Queue: Relational operator overloads", "[Queue]") {
	ft::queue<int> a;
	a.push(10);
	a.push(20);
	a.push(30);
	ft::queue<int> b;
	b.push(10);
	b.push(20);
	b.push(30);
	ft::queue<int> c;
	c.push(30);
	c.push(20);
	c.push(10);

	REQUIRE((a == b) == true);
	REQUIRE((b != c) == true);
	REQUIRE((b < c) == true);
	REQUIRE((c > b) == true);
	REQUIRE((a <= b) == true);
	REQUIRE((a >= b) == true);

	REQUIRE((a <= b) == true);
	REQUIRE((a > b) == false);
	REQUIRE((a < b) == false);
	REQUIRE((a != b) == false);
	REQUIRE((b > c) == false);
	REQUIRE((b == c) == false);
	REQUIRE((b != c) == true);
}
