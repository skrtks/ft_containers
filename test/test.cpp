#define CATCH_CONFIG_MAIN
#include "Catch2.h"

#include "list.hpp"
#include <list>

TEST_CASE("Iterator", "[List]") {
	ft::list<std::string> myList;
	std::list<std::string> sysList;
	ft::list<int> myIntList;
	std::string str = "Hello, world!";
	myList.push_back(str);
	sysList.push_back(str);
	myList.push_back("I'm the next King");
	sysList.push_back("I'm the next King");
	myList.push_back("Welcome yourself to the next chapter");
	sysList.push_back("Welcome yourself to the next chapter");
	ft::list<std::string>::iterator myIt = myList.begin();
	std::list<std::string>::iterator sysIt = sysList.begin();

	SECTION("Increment") {
		myIt++;
		sysIt++;
		REQUIRE(*myIt == *sysIt);
		++myIt;
		++sysIt;
		REQUIRE(*myIt == *sysIt);
	}
	SECTION("Decrement") {
		myIt++;
		sysIt++;
		REQUIRE(*myIt == *sysIt);
		myIt--;
		sysIt--;
		REQUIRE(*myIt == *sysIt);
	}
	SECTION("-> overload") {
		myIt++;
		sysIt++;
		REQUIRE(*myIt->data() == *sysIt->data());
	}
	SECTION("* overload") {
		myIt++;
		sysIt++;
		REQUIRE(*myIt == *sysIt);
	}
	SECTION("== overload") {
		bool res;
		res = (myIt == myList.begin());
		REQUIRE(res == true);
		myIt++;
		myIt++;
		myIt++;
		res = (myIt == myList.end());
		REQUIRE(res == true);
		res = (myIt == myList.begin());
		REQUIRE(res == false);
	}
	SECTION("!= overload") {
		bool res;
		res = (myIt != myList.end());
		REQUIRE(res == true);
		myIt++;
		myIt++;
		res = (myIt != myList.begin());
		REQUIRE(res == true);
		myIt++;
		res = (myIt != myList.end());
		REQUIRE(res == false);
	}
	SECTION("Test (*it)++") {
		myIntList.push_back(1);
		ft::list<int>::iterator myIntIt = myIntList.begin();
		REQUIRE(*myIntIt == 1);
		(*myIntIt)++;
		REQUIRE(*myIntIt == 2);
		*myIntIt++;
		bool res = (myIntIt == myIntList.end());
		REQUIRE(res == true);
	}
	SECTION("Test (*it)--") {
		myIntList.push_back(2);
		ft::list<int>::iterator myIntIt = myIntList.begin();
		REQUIRE(*myIntIt == 2);
		(*myIntIt)--;
		REQUIRE(*myIntIt == 1);
		*myIntIt--;
		bool res = (myIntIt != myIntList.begin());
		REQUIRE(res == true);
	}
	SECTION("Test assignemt with iterator") {
		myIntList.push_back(1);
		myIntList.push_back(8);
		ft::list<int>::iterator myIntIt = myIntList.begin();
		REQUIRE(*myIntIt == 1);
		*myIntIt = 5;
		REQUIRE(*myIntIt == 5);
	}
	SECTION("Test dereference as lvalue") {
		myIntList.push_back(1);
		myIntList.push_back(8);
		ft::list<int>::iterator myIntIt = myIntList.begin();
		*myIntIt++ = 5;
		REQUIRE(*myIntIt == 8);
		myIntIt--;
		REQUIRE(*myIntIt == 5);
	}
	SECTION("Reverse iterator") {
		ft::list<int> mylist;
		for (int i=1; i<=5; ++i) mylist.push_back(i);

		ft::list<int>::reverse_iterator rit=mylist.rbegin();
		REQUIRE(*rit == 5);
		rit++;
		REQUIRE(*rit == 4);
		rit--;
		REQUIRE(*rit == 5);
		*rit = 10;
		REQUIRE(*rit == 10);
	}
}

TEST_CASE("Push-front", "[List]") {
	ft::list<int> myList;
	myList.push_back(1);
	myList.push_front(2);
	myList.push_front(26);
	ft::list<int>::iterator it = myList.begin();
	REQUIRE(*it == 26);
	it++;
	REQUIRE(*it == 2);
}

TEST_CASE("Pop-front", "[List]") {
	ft::list<int> myList;
	myList.push_back(1);
	myList.push_back(2);
	myList.push_back(3);
	myList.pop_front();
	myList.pop_front();
	ft::list<int>::iterator it = myList.begin();
	REQUIRE(*it == 3);
}

TEST_CASE("Pop-back", "[List]") {
	ft::list<int> myList;
	myList.push_back(1);
	myList.push_back(2);
	myList.push_back(3);
	myList.pop_back();
	myList.pop_back();
	ft::list<int>::iterator it = myList.begin();
	REQUIRE(*it == 1);
}

