//////////////////////////////////////////////////////////////////////
/// @file  play_variadic_templ.cpp
/// @author jb090979@web.de
/// Copyright (c) 2022 by Jens Baumann
/// License:  Give me chocolate and you can use the code :-)
//////////////////////////////////////////////////////////////////////

#include "play_decltype.hpp"
#include "write_type.hpp"
#include <boost/type_index.hpp>
#include <iostream>
#include <queue>
#include <stdint.h>

namespace play_variadic_templ {


template <typename First>
void print_types(const First& value)
{
   std::cout << "Type: " << write_type::get_type_name(value) << "\n";
}

template <typename First, typename... Args>
void print_types(const First& value, Args... args)
{
   std::cout << "Type: " << write_type::get_type_name(value) << " | type count: " << sizeof...(args) << "\n";
   print_types(args...);
}

void run()
{
   std::cout << "####################################\n";

   std::cout << "list types\n";
   const uint32_t x  = 27;
   const auto&    xr = x;

   print_types(UINT16_C(1), 1.2f, 123455, 1.23445667890, x, xr);
}
}   // namespace play_variadic_templ
