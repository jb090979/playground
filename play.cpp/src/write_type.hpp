//////////////////////////////////////////////////////////////////////
/// @file  write_type.hpp
/// @author jb090979@web.de
/// Copyright (c) 2022 by Jens Baumann
/// License:  Give me chocolate and you can use the code :-)
//////////////////////////////////////////////////////////////////////

#ifndef PLAYCPP_WRITE_TYPE_HPP
#define PLAYCPP_WRITE_TYPE_HPP

#include <stdint.h>
#include <string>
#include <type_traits>
#include <iostream>
#include <boost/type_index.hpp>

namespace write_type {

template<typename T>
class TD;

template <typename T>
std::string get_type_name(const T& param)
{
   return std::string(boost::typeindex::type_id_with_cvr<T>().pretty_name());
}

template <typename T>
void write_type_r(const T& param)
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
void write_type_ur(T&& param)
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
void write_type_param(T param)
{
   using boost::typeindex::type_id_with_cvr;
   using std::cout;

   cout << "Type T with typeid(T) --> " << typeid(T).name() << "\n";
   cout << "Type T with type_id_with_cvr(T) --> " << type_id_with_cvr<T>().pretty_name() << "\n";

   cout << "Type param with typeid(param) --> " << typeid(param).name() << "\n";
   cout << "Type param with type_id_with_cvr(decltype(param)) --> " << type_id_with_cvr<decltype(param)>().pretty_name() << "\n";
   cout << "\n\n";
}

}

#endif
