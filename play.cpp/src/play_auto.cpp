//////////////////////////////////////////////////////////////////////
/// @file  play_auto.cpp
/// @author jb090979@web.de
/// Copyright (c) 2022 by Jens Baumann
/// License:  Give me chocolate and you can use the code :-)
//////////////////////////////////////////////////////////////////////

#include "play_auto.hpp"
#include <boost/type_index.hpp>
#include <iostream>
#include <stdint.h>
namespace play_auto {

template <typename T>
void write_type(const T& param)
{
   using boost::typeindex::type_id_with_cvr;
   using std::cout;

   cout << "Type T with typeid(T) --> " << typeid(T).name() << "\n";
   cout << "Type T with type_id_with_cvr(T) --> " << type_id_with_cvr<T>().pretty_name() << "\n";

   cout << "Type param with typeid(param) --> " << typeid(param).name() << "\n";
   cout << "Type param with type_id_with_cvr(decltype(param)) --> " << type_id_with_cvr<decltype(param)>().pretty_name() << "\n";
   cout << "\n\n";
}

template <typename T>
void write_type2(T&& param)
{
   using boost::typeindex::type_id_with_cvr;
   using std::cout;

   cout << "Type T with typeid(T) --> " << typeid(T).name() << "\n";
   cout << "Type T with type_id_with_cvr(T) --> " << type_id_with_cvr<T>().pretty_name() << "\n";

   cout << "Type param with typeid(param) --> " << typeid(param).name() << "\n";
   cout << "Type param with type_id_with_cvr(decltype(param)) --> " << type_id_with_cvr<decltype(param)>().pretty_name() << "\n";
   cout << "\n\n";
}


template <typename T>
void write_type3(T param)
{
   using boost::typeindex::type_id_with_cvr;
   using std::cout;

   cout << "Type T with typeid(T) --> " << typeid(T).name() << "\n";
   cout << "Type T with type_id_with_cvr(T) --> " << type_id_with_cvr<T>().pretty_name() << "\n";

   cout << "Type param with typeid(param) --> " << typeid(param).name() << "\n";
   cout << "Type param with type_id_with_cvr(decltype(param)) --> " << type_id_with_cvr<decltype(param)>().pretty_name() << "\n";
   cout << "\n\n";
}

decltype(auto) f1()
{
   uint32_t x = UINT32_C(0);
   return x;
}

decltype(auto) f2()
{
   uint32_t x = UINT32_C(0);
   return (x);
}

auto f3()
{
   uint32_t x = UINT32_C(0);
   return x;
}

auto f4()
{
   uint32_t x = UINT32_C(0);
   return (x);
}

//template to determine array size
template<typename T, std::size_t N>
constexpr std::size_t arraySize(T (&)[N])
{
    return N;
}

void run()
{
   auto i = 3.1234567;

   write_type(i);
   write_type(3.1234567);

   std::cout << "####################################\n";
   std::cout << "Function types\n";
   write_type(f1);
   write_type(f2);
   write_type(f3);
   write_type(f4);


   std::cout << "####################################\n";
   std::cout << "ParamType is a reference or a pointer, but not universal reference\n";
   int        x  = 27;
   const int  cx = x;
   const int& rx = x;
   write_type(x);
   write_type(cx);
   write_type(rx);
   write_type(27);


   std::cout << "####################################\n";
   std::cout << "ParamType is a universal reference\n";
   write_type2(x);
   write_type2(cx);
   write_type2(rx);
   write_type2(27);

   std::cout << "####################################\n";
   std::cout << "ParamType is a no reference and no pointer\n";
   write_type3(x);
   write_type3(cx);
   write_type3(rx);
   write_type3(27);

   std::cout << "####################################\n";
   std::cout << "Array types\n";
   const char  name[]    = "Jens Baumann";
   const char* ptrToName = name;
   write_type3(name);
   write_type(name);

   write_type3(ptrToName);
   std::cout << "Length of name (template) : " << arraySize(name) << "\n";
   std::cout << "Length of name (old style): " << sizeof(name)/sizeof(name[0]) << "\n";


   std::cout << "####################################\n";
   std::cout << "auto types\n";
   auto x2 = 27;
   const auto cx2 = x2;
   const auto& rx2 = x2;
   write_type(x2);
   write_type(cx2);
   write_type(rx2);
   write_type2(x2);
   write_type2(cx2);
   write_type2(rx2);
   write_type3(x2);
   write_type3(cx2);
   write_type3(rx2);


   std::cout << "####################################\n";
   std::cout << "special case for auto types vs templates\n";
   auto n = 27;
   auto n2(27);
   auto n3 = {27};
   auto n4{27};
   write_type(n);
   write_type(n2);
   write_type(n3);
   write_type(n4);







}

}   // namespace play_auto
