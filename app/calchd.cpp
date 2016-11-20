/////////////////////////////////////////////////////////////////////////
// Copyright (C) 2016 Sergey Koshelev                                   
/////////////////////////////////////////////////////////////////////////
#include "../lib/HammingDistance.h"

#include <iostream>

int main( int argc, char ** argv )
{
   if ( argc != 3 && argc != 4 )
   {
      std::cout << "Utility to calculate Hamming distance between 2 strings\n"
         << "Usage: calchd [-b] <str1> <str2>\n"
         << " -b : force to treat strings as binary data and calculate Hamming distance as bitwise\n"
         << " str1 and str2 input strings to calculate Hamming distance.\n";
   }
   
   bool binaryInp = false;

   // parse input arguments
   if ( std::string( argv[1] ) == "-b" ) { binaryInp = true; }
   
   std::string str1 = argv[argc - 2];
   std::string str2 = argv[argc - 1];
   
   size_t dist = binaryInp ? HammingDistance::calculate( str1.c_str(), str2.c_str() ) :
                             HammingDistance::calculate( str1, str2 );
   std::cout << "Hamming distance between " << str1 << " and " << str2 << " is: " << dist << "\n";

   return 0;
}


