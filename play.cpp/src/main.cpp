#include "play.hpp"
#include "play_auto.hpp"
#include "play_decltype.hpp"
#include "play_variadic_templ.hpp"
#include <iostream>

int main()
{
    std::cout << "Play Part:\n";
    //play::run();

    std::cout << "\n\nPlay Auto Part:\n";
    //play_auto::run();


    std::cout << "\n\nPlay Decltype Part:\n";
    //play_decltype::run();


    std::cout << "\n\nPlay Variadic Templates Part:\n";
    play_variadic_templ::run();
    return 0;
}
