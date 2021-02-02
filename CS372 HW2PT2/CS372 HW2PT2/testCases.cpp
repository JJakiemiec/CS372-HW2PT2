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
	REQUIRE(gameOfLife("OOO\nOOO\nOOO\nOOO") == "ERROR: incorrect board format");
}

TEST_CASE("A living cell with less than two neighbors: dies!") {
	REQUIRE(gameOfLife("XXX\nXXX\nXXX") == "XXX\nXXX\nXXX");
	REQUIRE(gameOfLife("XXX\nXOX\nXXX") == "XXX\nXXX\nXXX");
	REQUIRE(gameOfLife("OOO\nXXX\nXXX") == "XOX\nXXX\nXXX");
	REQUIRE(gameOfLife("OXO\nXXX\nOXO") == "XXX\nXXX\nXXX");
}

TEST_CASE("A living cell with four neighbors: dies!") {
	REQUIRE(gameOfLife("OOO\nOOO\nOOO") == "OOO\nOXO\nOOO");
	REQUIRE(gameOfLife("XOX\nOOO\nXOX") == "XXX\nXXX\nXXX");
	REQUIRE(gameOfLife("OOX\nOOO\nXOX") == "OOX\nOXX\nXXX");
}

TEST_CASE("A dead cell with exactly three neighbors: becomes alive!") {
	REQUIRE(gameOfLife("OXO\nXOX\nXXX") == "XXX\nXOX\nXXX");
	REQUIRE(gameOfLife("XOX\nOXO\nXXX") == "XXX\nXOX\nXXX");
	REQUIRE(gameOfLife("OOO\nOOX\nOOO") == "OOO\nOXO\nOOO");
}