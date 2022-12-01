//////////////////////////////////////////////////////////////////////
/// @file  play_bind.cpp
/// @author jb090979@web.de
/// Copyright (c) 2022 by Jens Baumann
/// License:  Give me chocolate and you can use the code :-)
//////////////////////////////////////////////////////////////////////

#include "play_bind.hpp"
#include "write_type.hpp"
#include <boost/type_index.hpp>
#include <functional>
#include <iostream>
#include <queue>
#include <stdint.h>

namespace play_bind {


int64_t multiply(int32_t x, int32_t y)
{
   return x * y;
}
void run()
{
   auto square = std::bind(&multiply, std::placeholders::_1, std::placeholders::_1);
   std::cout << "Square 3 = " << square(3) << "\n";


   auto last_call = std::bind(&multiply, 1, 1);
   for (int32_t i = 1; i < 100; i++)
   {
      auto next_call = std::bind(square, i);
      std::cout << "Square " << i << " = " << next_call() << "\n";
   }
}
}   // namespace play_bind
