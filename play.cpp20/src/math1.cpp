//////////////////////////////////////////////////////////////////////
/// @file  math.ixx
/// @author jb090979@web.de
/// Copyright (c) 2022 by Jens Baumann
/// License:  Give me chocolate and you can use the code :-)
//////////////////////////////////////////////////////////////////////
module;

#include <cstdint>
#include <iostream>
#include <limits>
#include <numeric>
#include <vector>
#include <cmath>
#include <concepts>

export module math;


export namespace math {


int add(int fir, int sec)
{
   return fir + sec;
}

int getProduct(const std::vector<int>& vec)
{
    return std::accumulate(vec.begin(), vec.end(), 1, std::multiplies<int>());
}


template < typename T, typename T2>
requires std::integral<T> || std::floating_point<T>
auto sum(T fir, T2 sec)
{
    return fir + sec;
}


template<typename T, typename IsIntegral>
struct Equality{};

template< typename T>
struct Equality<T, std::true_type>
{
    Equality(T a, T b) { value = (a == b); }
    bool value;
};

template< typename T>
struct Equality<T, std::false_type>
{
    Equality(T a, T b) { value = (std::abs(a-b) < 0.00001); }
    bool value;
};

template< typename T>
bool isEqual(T a, T b)
{
    return Equality<T, typename std::is_integral<T>::type>(a,b).value;
}
}
