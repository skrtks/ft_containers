#include "Catch2.h"

#include "Vector.hpp"
#include <list>

TEST_CASE("Default constructor", "[Vector]") {
	ft::vector<int> myvector;
	REQUIRE(myvector.capacity() == 0);
	REQUIRE(myvector.empty() == true);
}