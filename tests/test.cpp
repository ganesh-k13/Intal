#include "../include/Intal.h"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("Testing addition operations", "[add]") {
	
	SECTION("Testing if simple addition works") {
		Intal num1("123456789");
		Intal num2("987654321");
		Intal result("1111111110");
		REQUIRE(((num1+num2) == result));
	}
	
	SECTION("Testing very large test-cases") {
		Intal num1("99999999999999999999999999999999999999999999999999999");
		Intal num2("99999999999999999999999999999999999999999999999999999");
		Intal result("199999999999999999999999999999999999999999999999999998");
		REQUIRE(((num1+num2) == result));
	}
	
	SECTION("Testing positive-negative test-cases") {
		Intal num1("99999999999999999999999999999999999999999999999999999");
		Intal num2("-99999999999999999999999999999999999999999999999999999");
		Intal result("0");
		REQUIRE(((num1+num2) == result));
	}
	
	SECTION("Testing negative-negative test-cases") {
		Intal num1("-99999999999999999999999999999999999999999999999999999");
		Intal num2("-99999999999999999999999999999999999999999999999999999");
		Intal result("-199999999999999999999999999999999999999999999999999998");
		REQUIRE(((num1+num2) == result));
	}
	
}

TEST_CASE("Testing subtraction operations", "[sub]") {
	
	SECTION("Testing if simple subtraction works") {
		Intal num1("123456789");
		Intal num2("987654321");
		Intal result("-864197532");
		REQUIRE(((num1-num2) == result));
	}
	
	SECTION("Testing very large test-cases") {
		Intal num1("99999999999999999999999999999999999999999999999999999");
		Intal num2("99999999999999999999999999999999999999999999999999999");
		Intal result("0");
		REQUIRE(((num1-num2) == result));
	}
	
	SECTION("Testing positive-negative test-cases") {
		Intal num1("99999999999999999999999999999999999999999999999999999");
		Intal num2("-99999999999999999999999999999999999999999999999999999");
		Intal result("199999999999999999999999999999999999999999999999999998");
		REQUIRE(((num1-num2) == result));
	}
	
	SECTION("Testing negative-negative test-cases") {
		Intal num1("-99999999999999999999999999999999999999999999999999999");
		Intal num2("-99999999999999999999999999999999999999999999999999999");
		Intal result("0");
		REQUIRE(((num1-num2) == result));
	}
	
	SECTION("Testing negative-positive test-cases") {
		Intal num1("-99999999999999999999999999999999999999999999999999999");
		Intal num2("99999999999999999999999999999999999999999999999999999");
		Intal result("-199999999999999999999999999999999999999999999999999998");
		REQUIRE(((num1-num2) == result));
	}
	
}