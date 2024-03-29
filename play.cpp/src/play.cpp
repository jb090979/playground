//////////////////////////////////////////////////////////////////////
/// @file  play.cpp
/// @author jb090979@web.de
/// Copyright (c) 2022 by Jens Baumann
/// License:  Give me chocolate and you can use the code :-)
//////////////////////////////////////////////////////////////////////

#include "play.hpp"
#include <iostream>
#include <limits>
#include <stdint.h>

namespace play {

//###### partiell Templates ######
template <typename T = int32_t, uint32_t n = 10>
class Array
{
public:
   enum
   {
      size = n
   };

   T& operator[](uint32_t i)
   {
      return data[ i ];
   }

   const T& max() const
   {
      T*       p         = nullptr;
      T        max       = data[ 0 ];
      uint32_t max_index = 0;
      for (uint32_t i = UINT32_C(1); i < n; i++)
      {
         if (data[ i ] > max)
         {
            max       = data[ i ];
            max_index = i;
         }
      }

      return data[ max_index ];
   }

   const T& min() const
   {
      T*       p         = nullptr;
      T        min       = data[ 0 ];
      uint32_t min_index = 0;
      for (uint32_t i = UINT32_C(1); i < n; i++)
      {
         if (data[ i ] < min)
         {
            min       = data[ i ];
            min_index = i;
         }
      }

      return data[ min_index ];
   }


private:
   T data[ n ];
};

template <typename T, uint32_t n>
class Array<T*, n>
{
public:
   enum
   {
      size = n
   };
   T& operator[](uint32_t i)
   {
      return data[ i ];
   }

private:
   T data[ n ];
};

void run()
{
   std::cout << "Template Array\n";

   Array<uint32_t, 5> a1;
   for (uint32_t i = 0; i < 5; i++)
   {
      a1[ i ] = i;
   }
   std::cout << "a1 max: " << a1.max() << "\n";
   std::cout << "a1 min: " << a1.min() << "\n";
   std::cout << "a1 size: " << a1.size << "\n";

   Array<uint32_t*, 2> a2;
   for (uint32_t i = 0; i < 2; i++)
   {
      a2[ i ] = 0;
   }
   // does not compile --> specialized array do not have min/max implemented
   // std::cout << "a2 max: " << a2.max() << "\n";
   // std::cout << "a2 min: " << a2.min() << "\n";
   std::cout << "a2 size: " << a2.size << "\n";

   // using default type/length
   Array<> a3;
   std::cout << "a3 size: " << a3.size << "\n";

   // using defaukt type/length
   Array<uint32_t*> a4;
   // does not compile --> specialized array do not have min/max implemented
   // std::cout << "a4 max: " << a4.max() << "\n";
   // std::cout << "a4 min: " << a4.min() << "\n";
   std::cout << "a4 size: " << a4.size << "\n";

   double x = 1;

   std::cout << "max of i: " << std::numeric_limits<decltype(x)>::max() << "\n";
}

}   // namespace play
