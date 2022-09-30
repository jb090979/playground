#include <iostream>
#include <vector>
#include <algorithm>

import math;
import coroutines;

template <typename>
struct Other;

template <>
struct Other<int>{};

template < typename T>
concept TypeRequirement = requires {
        typename T::value_type;
        typename Other<T>;
        };

template < typename T>
concept Integral = std::is_integral<T>::value;


int main()
{
    std::cout << "Play Modules:\n";
    std::cout << "add(2000,20) = " << math::add(2000,20) << "\n";
    std::vector<int> myVec{1,2,3};
    std::cout << "getProduct(myVec): " << math::getProduct(myVec) << "\n";

    std::cout << "sum(2000, 11): " << math::sum(2000,11) << "\n";
    std::cout << "sum(2000.5, 11): " << math::sum(2000.5,11) << "\n";
    std::cout << "sum(2000.5, true): " << math::sum(2000.5,true) << "\n";

    int a = 8;
    int b = 7;

    std::cout << "8==7: " << math::isEqual(8,7) << "\n";
    std::cout << "8==7: " << math::isEqual(8.1,7.1) << "\n";
    std::cout << "8==7: " << math::isEqual(8.1,8.1) << "\n";
    std::cout << "\n";

    //limit auto to take only integral types, like int or unsigned int
    std::integral auto x = 2;
    Integral auto x2 = 3;
    std::cout << "x: " << x << "\n";
    std::cout << "x2: " << x2 << "\n";
    std::cout << "\n";


    //test my concept
    //it is the example from the c20 book --> but it doesn't compile, concept requirement not matched.
    //TypeRequirement auto myVec = std::vector<int>{1,2,3};


    std::cout << "\nPlay ranges\n";


    std::vector<int> myVec2{-3, 5, 0, 7, -4};

    //oldstyle sort
    std::sort(myVec2.begin(), myVec2.end());
    std::cout << "old style\n";
    for (auto v: myVec2) std::cout << v << " " ;

    //c++20 style
    std::ranges::sort(myVec2);
    std::cout << "\n\nc++20 style\n";
    for (auto v: myVec2) std::cout << v << " " ;

    std::cout << "\n\nnsum(2000.5, 11): " << math::sum(2000.5,11) << "\n";
    std::cout << "sum(2000.5, true): " << math::sum(2000.5,true) << "\n";


    std::cout << "\nCoroutines ranges\n";

    const auto numbers = coroutines::generatorForNumbers(-10, 10, 2);

    for (auto i : numbers)
    {
        std::cout << i << " ";
    }

    std::cout << "\nstop playing\n";
    return 0;
}
