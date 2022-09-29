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

export module math;


export int add(int fir, int sec)
{
   return fir + sec;
}

export int getProduct(const std::vector<int>& vec)
{
    return std::accumulate(vec.begin(), vec.end(), 1, std::multiplies<int>());
}
