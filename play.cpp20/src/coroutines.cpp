//////////////////////////////////////////////////////////////////////
/// @file  coroutines.cpp
/// @author jb090979@web.de
/// Copyright (c) 2022 by Jens Baumann
/// License:  Give me chocolate and you can use the code :-)
//////////////////////////////////////////////////////////////////////
module;

#include <cstdint>
#include <iostream>
#include <concepts>
#include <coroutine>
#include <vector>

export module coroutines;


export namespace coroutines {


std::vector<int> generatorForNumbers(int begin, int end, int inc = 1)
{
    std::vector<int> numbers;
    for (int i = begin;i<end; i+=inc)
    {
        numbers.push_back(i);
    }
    return numbers;
}

}
