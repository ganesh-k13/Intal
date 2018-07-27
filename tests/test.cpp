#include "../include/Intal.h"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("Testing available mathematical operations", "[intal]") {
	Intal num1("123456789");
	Intal num2("987654321");
	
	SECTION("Testing if addition works") {
		Intal result("1111111110");
		REQUIRE(((num1+num2) == result));
	}
	
}