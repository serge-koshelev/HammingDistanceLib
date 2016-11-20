/////////////////////////////////////////////////////////////////////////
// Copyright (C) 2016 Sergey Koshelev                                   
/////////////////////////////////////////////////////////////////////////

#ifndef HAMMING_DISTANCE_H
#define HAMMING_DISTANCE_H

#include <algorithm>
#include <type_traits>
#include <string>

//////////////////////////////////////////////////////////////////////////////////
/// @mainpage Library to calculate Hamming distance
///
/// In information theory, the Hamming distance between two strings of equal 
/// length is the number of positions at which the corresponding symbols are different.
/// In another way, it measures the minimum number of substitutions required to change 
/// one string into the other, or the minimum number of errors that could have transformed 
///  one string into the other.
///
/// A major application is in coding theory, more specifically to block codes, in which the 
/// equal - length strings are vectors over a finite field.
///
/// For more details @sa https://en.wikipedia.org/wiki/Hamming_distance
/// 
/// This is a test project to demonstrate skills of C++ development
//////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////
/// @namespace HammingDistance
/// @brief Set of templated functions to calculate Hamming distance between to binary data blobs.
///
/// Template parameter could be only the fundamental C/C++ data type.
///
/// The typical usage:
///      
///      // for binary data with equal size blobs:
///      double * buf1 = new double [100];
///      double * buf2 = new double [100];
///      ... // to fill buffers with some values
///      size_t dist = HammingDistance::calculate( buf1, buf2, 100 );
///
///      // for '\0' ending strings
///      const char * str1 = "string1";
///      const char * str2 = "string2";
///      size_t dist = HammingDistance::calculate( str1, str2 );
///
//////////////////////////////////////////////////////////////////////////////////
namespace HammingDistance
{
   /// @brief Calculates Hamming distance for the given two binary blobs of equal size.
   /// @param blob1 the first blob
   /// @param blob2 the second blob
   /// @param sz size of the blobs. They must be the same size
   /// @return the calculated Hamming distance between blob1 and blob2
   template <typename T> size_t calculate( const T * blob1, const T * blob2, size_t sz );
   
   /// @brief Calculates Hamming distance for the given two binary blobs of different sizes
   /// @param blob1 the first blob
   /// @param blob2 the second blob
   /// @param sz1 size of the first blob
   /// @param sz2 size of the second blob      
   /// @return the calculated Hamming distance between blob1 and blob2
   template <typename T> size_t calculate( const T * blob1, const T * blob2, size_t sz1, size_t sz2 );
   
   /// @brief Calculates Hamming distance for the given two binary blobs. Blob size is defined by '\0' value at the blobs end.
   /// @param blob1 the first blob
   /// @param blob2 the second blob
   /// @return the calculated Hamming distance between blob1 and blob2
   template <typename T> size_t calculate( const T * blob1, const T * blob2 );

   /// @brief Special case - calculate Hamming distance as number of different characters in strings
   /// @param str1 the first string
   /// @param str2 the second string
   /// @return the number of different characters in strings.
   size_t calculate( const std::string & str1, const std::string & str2 );
}

/// @cond 
//////////////////////////////////////////////////////////////////////////////////
// Implementation part
//////////////////////////////////////////////////////////////////////////////////

// Equal sized blobs
template <typename T> static size_t HammingDistance::calculate( const T * blob1, const T * blob2, size_t sz )
{
   // Here we can deal only with simple data types like double, integer, char ...
   static_assert( std::is_fundamental<T>::value, "This Hamming distance implementation could deal with fundamental data types only" );

   size_t byteSize = sizeof( T );
   size_t dist = 0;
   
   for( size_t i = 0; i < sz; ++i ) // loop over blobs size
   {  // split element to bytes
      const unsigned char * b1 = reinterpret_cast<const unsigned char *> ( blob1 + i );
      const unsigned char * b2 = reinterpret_cast<const unsigned char *> ( blob2 + i );
      for ( size_t j = 0; j < byteSize; ++j ) // loop over all bytes in element
      {
         unsigned char diff = *(b1+j) ^ *(b2+j);     // xor-ing bytes
         while( diff ) { ++dist; diff &= diff - 1; } // calculate the number of different bits
      }
   }
   return dist;
}

// Blobs with different sizes
template <typename T> static size_t HammingDistance::calculate( const T * blob1, const T * blob2, size_t sz1, size_t sz2 )
{
   // find the minimal size and add difference in sizes to distance
   size_t dist = ( std::max( sz1, sz2 ) - std::min( sz1, sz2 ) ) * sizeof( T ) * 8; 

   // calculate distance
   return dist + calculate( blob1, blob2, std::min( sz1, sz2 ) );
}

// Null terminated blobs with (possible) different sizes
template <typename T> static size_t HammingDistance::calculate( const T * blob1, const T * blob2 )
{
   // find blobs sizes
   size_t sz1 = 0;
   while( *(blob1 + sz1) ) { ++sz1; }
   size_t sz2 = 0;
   while( *(blob1 + sz2) ) { ++sz2; }

   // calculate distance
   return calculate( blob1, blob2, sz1, sz2 );
}
/// @endcond
#endif // HUMMING_DISTANCE_H