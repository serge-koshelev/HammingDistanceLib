/////////////////////////////////////////////////////////////////////////
// Copyright (C) 2016 Sergey Koshelev                                    
/////////////////////////////////////////////////////////////////////////
#include "HammingDistance.h"


namespace HammingDistance
{
   size_t calculate( const std::string & str1, const std::string & str2 )
   {
      size_t dist = std::max( str1.size(), str2.size() ) - std::min( str1.size(), str2.size() );
      for ( size_t i = 0; i < std::min( str1.size(), str2.size() ); ++i )
      {
         dist += str1[ i ] == str2[ i ] ? 0 : 1;
      }
      return dist;
   }
}
