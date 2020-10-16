#define CATCH_CONFIG_MAIN
#include "Catch2.h"

#include "list.hpp"
#include <list>

TEST_CASE("Iterator", "[List]") {
	ft::list<std::string> myList;
	std::list<std::string> sysList;
	std::string str = "Hello, world!";
	myList.push_back(str);
	sysList.push_back(str);
	myList.push_back("I'm the next King");
	sysList.push_back("I'm the next King");
	myList.push_back("Welcome yourself to the next chapter");
	sysList.push_back("Welcome yourself to the next chapter");

	SECTION("Increment") {
		ft::list<std::string>::iterator myIt = myList.begin();
		std::list<std::string>::iterator sysIt = sysList.begin();
		myIt++;
		sysIt++;
		REQUIRE(*myIt == *sysIt);
		++myIt;
		++sysIt;
		REQUIRE(*myIt == *sysIt);
	}
	SECTION("Decrement") {
		ft::list<std::string>::iterator myIt = myList.begin();
		std::list<std::string>::iterator sysIt = sysList.begin();
		myIt++;
		sysIt++;
		REQUIRE(*myIt == *sysIt);
		myIt--;
		sysIt--;
		REQUIRE(*myIt == *sysIt);
	}
}