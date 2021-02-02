//Jacob Jakiemiec
//TestCases.cpp

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "gameOfLife.hpp"

TEST_CASE("A wrongly formated board gives an error") {
	REQUIRE(gameOfLife("") == "ERROR: incorrect board format");
	REQUIRE(gameOfLife("asdf") == "ERROR: incorrect board format");
	REQUIRE(gameOfLife("ooo\nooo\nooo") == "ERROR: incorrect board format");
	REQUIRE(gameOfLife("OOO\nOOO\nOOo") == "ERROR: incorrect board format");
	REQUIRE(gameOfLife("XXX\nXXX\nXXx") == "ERROR: incorrect board format");
	REQUIRE(gameOfLife("XXX\nXXX\nXXX") != "ERROR: incorrect board format");
	REQUIRE(gameOfLife("OOO\nOOO\nOOO") != "ERROR: incorrect board format");
}