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

TEST_CASE("Assign", "[List]") {
	ft::list<int>	oneL;
	std::list<int>	twoL;
	twoL.push_back(1);
	twoL.push_back(2);
	twoL.push_back(3);

	oneL.assign(twoL.begin(), twoL.end());
	ft::list<int>::iterator it = oneL.begin();
	REQUIRE(*it == 1);
	it++;
	REQUIRE(*it == 2);
	REQUIRE(oneL.getSize() == 3);

	oneL.assign(4, 300);
	it = oneL.begin();
	REQUIRE(*it == 300);
	it++;
	REQUIRE(*it == 300);
	REQUIRE(oneL.getSize() == 4);

	int myint[5] = {1, 2, 3, 4, 5};
	oneL.assign(myint, myint + 5);
	it = oneL.begin();
	REQUIRE(*it == 1);
	it++;
	REQUIRE(*it == 2);
	REQUIRE(oneL.getSize() == 5);
}

TEST_CASE("Insert", "[List]") {
	ft::list<int> mylist;
	ft::list<int>::iterator it;

	// set some initial values:
	for (int i=1; i<=5; ++i) mylist.push_back(i); // 1 2 3 4 5

	it = mylist.begin();
	++it;       // it points now to number 2           ^
	REQUIRE(*it == 2);
	mylist.insert (it,10);                        // 1 10 2 3 4 5
	REQUIRE(mylist.getSize() == 6);
	// "it" still points to number 2                           ^
	mylist.insert (it,2,20);                      // 1 10 20 20 2 3 4 5
	REQUIRE(mylist.getSize() == 8);
	--it;       // it points now to the second 20            ^
	REQUIRE(*it == 20);
	std::vector<int> myvector (2,30);
	mylist.insert (it,myvector.begin(),myvector.end());
	// 1 10 20 30 30 20 2 3 4 5
	//               ^
	it--;
	REQUIRE(*it == 30);
	REQUIRE(mylist.getSize() == 10);
}

TEST_CASE("Erase", "[List]") {
	ft::list<int> mylist;
	ft::list<int>::iterator it1,it2;
	// set some values:
	for (int i=1; i<10; ++i) mylist.push_back(i*10);
										// 10 20 30 40 50 60 70 80 90
	it1 = it2 = mylist.begin(); 		// ^^
	advance (it2,6);				// ^                 ^
	++it1;								//    ^              ^
	REQUIRE(mylist.getSize() == 9);
	REQUIRE(*it1 == 20);
	REQUIRE(*it2 == 70);
	it1 = mylist.erase (it1);   // 10 30 40 50 60 70 80 90
								//    ^           ^
	REQUIRE(*it1 == 30);
	REQUIRE(*it2 == 70);
	REQUIRE(mylist.getSize() == 8);
	it2 = mylist.erase (it2);	// 10 30 40 50 60 80 90
								//    ^           ^
	++it1;						//       ^        ^
	--it2;						//       ^     ^
	REQUIRE(*it1 == 40);
	REQUIRE(*it2 == 60);
	REQUIRE(mylist.getSize() == 7);
	it1 = mylist.erase (it1,it2);		// 10 30 60 80 90
										//       ^
	REQUIRE(*it1 == 60);
	REQUIRE(*it2 == 60);
	REQUIRE(mylist.getSize() == 5);
}

TEST_CASE("Swap", "[List]") {
	ft::list<int> first (3,100);   // three ints with a value of 100
	ft::list<int> second (5,200);  // five ints with a value of 200

	first.swap(second);

	ft::list<int>::iterator it=first.begin();
	REQUIRE(*it == 200);
	it = second.begin();
	REQUIRE(*it == 100);
}

TEST_CASE("Resize", "[List]") {
	ft::list<int> mylist;

	// set some initial content:
	for (int i=1; i<10; ++i) mylist.push_back(i);

	mylist.resize(5);
	REQUIRE(mylist.getSize() == 5);
	mylist.resize(8,100);
	REQUIRE(mylist.getSize() == 8);
	mylist.resize(12);
	REQUIRE(mylist.getSize() == 12);
}

