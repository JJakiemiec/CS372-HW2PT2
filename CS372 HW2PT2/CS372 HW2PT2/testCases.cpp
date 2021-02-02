//Jacob Jakiemiec
//TestCases.cpp

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "gameOfLife.hpp"

TEST_CASE("A wrongly formated board gives an error") {
	REQUIRE("" == "ERROR: incorrect board format");
	REQUIRE("asdf" == "ERROR: incorrect board format");
	REQUIRE("ooo\nooo\nooo" == "ERROR: incorrect board format");
	REQUIRE("OOO\nOOO\nOOo" == "ERROR: incorrect board format");
	REQUIRE("XXX\nXXX\nXXx" == "ERROR: incorrect board format");
	REQUIRE("XXX\nXXX\nXXX" != "ERROR: incorrect board format");
	REQUIRE("OOO\nOOO\nOOO" != "ERROR: incorrect board format");
}