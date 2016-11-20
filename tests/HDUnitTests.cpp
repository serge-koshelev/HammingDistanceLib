/////////////////////////////////////////////////////////////////////////
// Copyright (C) 2016 Sergey Koshelev                                   
/////////////////////////////////////////////////////////////////////////

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE "HammingDistanceClass"

#include <boost/test/unit_test.hpp>

#include "../lib/HammingDistance.h"

BOOST_AUTO_TEST_CASE( calculateBlobsEqSz )
{
   // 2 bytes completely different
   unsigned int a = 0xFFFF;
   unsigned int b = 0x0000;
   BOOST_CHECK( HammingDistance::calculate( &a, &b, 1 ) == 16 );

   // move 1 set bit through integer and calculate Hamming distance. Must be always 1
   for ( int i = 0; i < sizeof( int ) * 8; ++i )
   {
      unsigned int a = 1 << i;
      unsigned int b = 0;
      BOOST_CHECK( HammingDistance::calculate( &a, &b, 1 ) == 1 );
   }

   // check array
   int aa[] = { 0xFFFF, 0x0000 };
   int bb[] = { 0xFFFE, 0x0010 };
   BOOST_CHECK( HammingDistance::calculate( aa, bb, 2 ) == 2 );
}

BOOST_AUTO_TEST_CASE( calculateBlobsDifSz )
{
   int aa[] = { 0xFFFF, 0x0000 };
   int bb[] = { 0xFFFF };
   BOOST_CHECK( HammingDistance::calculate( aa, bb, 2, 1 ) == sizeof(int)*8 );
}

BOOST_AUTO_TEST_CASE( calculateBlobsZeroTerm )
{
   int aa[] = { 0xFFFF, 0xFFFF, 0x1000, 0 };
   int bb[] = { 0xFFFF, 0xFEFF, 0x0100, 0 };
   BOOST_CHECK( HammingDistance::calculate( aa, bb ) == 3 );
}

BOOST_AUTO_TEST_CASE( calculateStrings )
{
   std::string a = "1011101";
   std::string b = "1001001";
   BOOST_CHECK( HammingDistance::calculate( a, b ) == 2 );

   a = "2173896";
   b = "2233796";
   BOOST_CHECK( HammingDistance::calculate( a, b ) == 3 );

   a = "2173896";
   b = "223379";
   BOOST_CHECK( HammingDistance::calculate( a, b ) == 4 );

}


