/**
*cpp file of assignment 3 Unit-Test
*Authors Alexey Titov and Shir Bentabou
*Version 1.0
**/
//libraries
#include <boost/test/minimal.hpp>
#include "Member.h"
using namespace std;
//global variables
Member avi, beni, chana;
//function
void testFunction(){
	Member dana;
	chana.follow(dana);
	dana.follow(avi);
	BOOST_REQUIRE( avi.numFollowers()==1);
	BOOST_REQUIRE( chana.numFollowing()==1);
	if( Member::count()!= 4 )
        BOOST_ERROR( "Ouch..." ); 
}
//main 
int test_main( int, char *[ ] ) // note the name! 
{
	//before follow
	BOOST_CHECK( avi.numFollowers()==0);
	BOOST_CHECK( beni.numFollowers()==0);
	BOOST_CHECK( avi.numFollowing()==0);
	BOOST_CHECK( beni.numFollowing()==0);
	//follow
	avi.follow(beni);
	BOOST_CHECK( beni.numFollowers()==1);
	BOOST_CHECK( avi.numFollowing()==1);
	//duplicate follow
	avi.follow(beni);
	BOOST_REQUIRE( avi.numFollowing()==1);
	//unfollow
	avi.unfollow(beni);
	BOOST_REQUIRE( beni.numFollowers()==0);
	BOOST_REQUIRE( avi.numFollowing()==0);
    if( Member::count()!= 3 )
        BOOST_FAIL( "Ouch..." ); 
	//function
	testFunction();
	return Member::count() == 3 ?  0 : 1; // #returns error code 
}