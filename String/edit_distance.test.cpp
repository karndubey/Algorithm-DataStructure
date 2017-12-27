#define Edit_Distance_TEST
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "edit_distance.cpp"
	TEST_CASE("string 1 is null") {
		string s1,s2;
	//s1 is null so outuput is length of s2
	s1="";
	s2="saturday";
    REQUIRE(editDistance(s1,s2) == 8);
	}
	TEST_CASE("String 2 is null") {
		string s1,s2;
	 	//s2 is null so outuput is length of s1
		s1="SUNDAY";
		s2="";
    	REQUIRE(editDistance(s1,s2) == 6);
	}
	TEST_CASE("both are different") {
		// both are different
		string s1,s2;
		s1="saturday";
		s2="sunday";
    	REQUIRE(editDistance(s1,s2) == 3);
	}
	TEST_CASE("both are same") {
		// both are different
		string s1,s2;
		s1="new";
		s2="new";
    	REQUIRE(editDistance(s1,s2) == 0);
	}
	

#undef Edit_Distance_TEST
