//////////////////////////////////////////////////////////////////////
/// @file  play_decltype.cpp
/// @author jb090979@web.de
/// Copyright (c) 2022 by Jens Baumann
/// License:  Give me chocolate and you can use the code :-)
//////////////////////////////////////////////////////////////////////

#include "play_decltype.hpp"
#include "write_type.hpp"
#include <boost/type_index.hpp>
#include <cstdint>
#include <iostream>
#include <queue>

namespace play_decltype {

template <typename Container, typename Index>
decltype(auto) authAndAcess(Container& c, Index i)
{
   return c[ i ];
}

void run()
{
   std::cout << "####################################\n";
   std::cout << "normal usecase\n";
   const uint32_t i = 0;
   write_type::write_type_r(i);
   std::cout << "type of i: " << write_type::get_type_name(i) << "\n";

   std::cout << "####################################\n";
   std::cout << "authAndAcess\n";
   std::deque<int> d;

   authAndAcess(d, 5) = 10;
}
}   // namespace play_decltype
