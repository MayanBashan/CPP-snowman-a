/**
 * Unit tests for snowman exercise
 * AUTHOR: Mayan Bashan
 * Date: 2021-03
 */

#include "doctest.h"
#include "snowman.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}

// checks if the actual snowman is the same as the expexted snowman
TEST_CASE("Good snowman"){
	//Hat
	CHECK(nospaces(snowman(11114411)) == nospaces(" _===_\n (.,.) \n ( : ) \n ( : ) "));	   
	CHECK(nospaces(snowman(21114411)) == nospaces("  ___ \n ..... \n (.,.) \n ( : ) \n ( : ) "));									
	CHECK(nospaces(snowman(31114411)) == nospaces("  _ \n /_\\\n (.,.) \n ( : ) \n ( : ) "));
	CHECK(nospaces(snowman(41114412)) == nospaces(" ___ \n (_*_) \n (.,.) \n ( : ) \n (\" \") "));
	
	//Nose or Mouth
	CHECK(nospaces(snowman(41143212)) == nospaces(" ___\n (_*_) \n (.,-)/\n/( : )\n (\" \") "));
	CHECK(nospaces(snowman(42143212)) == nospaces(" ___\n (_*_) \n (..-)/\n/( : )\n (\" \") "));
	CHECK(nospaces(snowman(43143212)) == nospaces(" ___\n (_*_) \n (._-)/\n/( : )\n (\" \") "));
	CHECK(nospaces(snowman(44143212)) == nospaces(" ___\n (_*_) \n (. -)/\n/( : )\n (\" \") "));		
	
	//Left or Right Eye
	CHECK(nospaces(snowman(41113212)) == nospaces(" ___ \n (_*_) \n (.,.)/\n/( : ) \n (\" \") "));
	CHECK(nospaces(snowman(41223212)) == nospaces(" ___ \n (_*_) \n (o,o)/\n/( : ) \n (\" \") "));
	CHECK(nospaces(snowman(41333212)) == nospaces(" ___ \n (_*_) \n (O,O)/\n/( : ) \n (\" \") "));
	CHECK(nospaces(snowman(41443212)) == nospaces(" ___ \n (_*_) \n (-,-)/\n/( : ) \n (\" \") "));

	// Left Arm
	CHECK(nospaces(snowman(24231214)) == nospaces(" ___ \n ..... \n (o O)/\n<( : ) \n (   ) "));
	CHECK(nospaces(snowman(24232214)) == nospaces(" ___ \n ..... \n\\(o O)/\n ( : ) \n (   ) "));
	CHECK(nospaces(snowman(24233214)) == nospaces(" ___ \n ..... \n (o O)/\n/( : ) \n (   ) "));
	CHECK(nospaces(snowman(24234214)) == nospaces(" ___ \n ..... \n (o O)/\n ( : ) \n (   ) "));

	// Right Arm
	CHECK(nospaces(snowman(24231114)) == nospaces("___ \n.....\n (o O) \n<( : )>\n (   ) "));
	CHECK(nospaces(snowman(24231214)) == nospaces("___ \n.....\n (o O)/\n<( : ) \n (   ) "));											 
	CHECK(nospaces(snowman(24231314)) == nospaces("___ \n.....\n (o O) \n<( : )\\\n (   ) "));
	CHECK(nospaces(snowman(24231414)) == nospaces("___ \n.....\n (o O) \n<( : ) \n (   ) "));										

	//Torso
	CHECK(nospaces(snowman(32221113)) == nospaces("  _  \n /_\\ \n (o.o) \n<( : )>\n (___) "));
	CHECK(nospaces(snowman(32221123)) == nospaces("  _  \n /_\\ \n (o.o) \n<(] [)>\n (___) "));
	CHECK(nospaces(snowman(32221133)) == nospaces("  _  \n /_\\ \n (o.o) \n<(> <)>\n (___) "));
	CHECK(nospaces(snowman(32221114)) == nospaces("  _  \n /_\\ \n (o.o) \n<(   )>\n (___) "));

	//Base
	CHECK(nospaces(snowman(32221111)) == nospaces("  _  \n /_\\ \n (o.o) \n<( : )>\n ( : ) "));
	CHECK(nospaces(snowman(32221112)) == nospaces("  _  \n /_\\ \n (o.o) \n<( : )>\n (\" \") "));
	CHECK(nospaces(snowman(32221113)) == nospaces("  _  \n /_\\ \n (o.o) \n<( : )>\n (___) "));
	CHECK(nospaces(snowman(32221114)) == nospaces("  _  \n /_\\ \n (o.o) \n<( : )>\n (   ) "));										   											   

}

//checks if number of digits does not equal 8
TEST_CASE("Bad input - number does not contain 8 digits"){
	
	CHECK_THROWS(snowman(1));
	CHECK_THROWS(snowman(24));
	CHECK_THROWS(snowman(421));
	CHECK_THROWS(snowman(2113));
	CHECK_THROWS(snowman(12344));
	CHECK_THROWS(snowman(111222));
	CHECK_THROWS(snowman(1123424));
	CHECK_THROWS(snowman(112142311));
}

//checks every digit is between 1-4
TEST_CASE("Bad input - 8 digits but not all digits are between 1-4"){
	CHECK_THROWS(snowman(-31243214)); // 1st digit < 0 (negative number)
	CHECK_THROWS(snowman(51214232)); // 1st digit > 4
	CHECK_THROWS(snowman(38433321)); // 2nd digit > 4
	CHECK_THROWS(snowman(12912241)); // 3rd digit > 4
	CHECK_THROWS(snowman(33261331)); // 4th digit > 4
	CHECK_THROWS(snowman(12345111)); // 5th digit > 4
	CHECK_THROWS(snowman(23232431)); // 6th digit > 4
	CHECK_THROWS(snowman(11111152)); // 7th digit > 4
	CHECK_THROWS(snowman(44123418)); // 8th digit > 4
}
