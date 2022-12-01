//////////////////////////////////////////////////////////////////////
/// @file  RomanNumber.cpp
/// @author jb090979@web.de
/// Copyright (c) 2022 by Jens Baumann
/// License:  Give me chocolate and you can use the code :-)
//////////////////////////////////////////////////////////////////////

#include "RomanNumber.hpp"
#include <bits/stdc++.h>
#include <stdexcept>
#include <string>

namespace roman_number {


RomanNumber::RomanNumber(std::string number)
{
   m_Number      = decode(number);
   m_RomanNumber = number;
}

RomanNumber::RomanNumber(const RomanNumber& _other) : m_Number(_other.m_Number), m_RomanNumber(_other.m_RomanNumber)
{
}

uint32_t RomanNumber::convertToArabic()
{
   return m_Number;
}


RomanNumber::~RomanNumber()
{
}

uint32_t roman_number::RomanNumber::decode(std::string roman_number)
{
   uint32_t number                     = UINT32_C(0);
   uint32_t last_number                = UINT32_C(0);
   uint32_t next_greatest              = UINT32_C(0);
   uint32_t last_greater_number        = UINT32_C(0);
   uint32_t consecutive_char_count     = UINT32_C(1);
   auto     invalid_char_error         = std::invalid_argument("Invalid character in roman number, only IVXLCDM alowed!");
   auto     invalid_equal_count_error  = std::invalid_argument("Only 3 consecutives equal characters allowed!");
   auto     invalid_lesser_count_error = std::invalid_argument("Only 1 consecutives lesser characters allowed befor a greater character!");
   auto     invalid_number_error       = std::invalid_argument("Invalid roman number!");
   auto invalid_sum_error = std::invalid_argument("Sum of 2 consecutive characters are greater then next higher character, e.g. VV --> X");
   auto unkown_error      = std::invalid_argument("Invalid operation!");

   // V,L, D appears only once and not consequtive
   std::string bad_numbers[] = { "VV", "LL", "DD" };
   for (auto& s : bad_numbers)
      if (roman_number.find(s) != std::string::npos)
         throw invalid_number_error;


   reverse(roman_number.begin(), roman_number.end());
   for (auto& ch : roman_number)
   {
      uint32_t n = 0;
      switch (ch)
      {
         case 'I': n = I; break;
         case 'V': n = V; break;
         case 'X': n = X; break;
         case 'L': n = L; break;
         case 'C': n = C; break;
         case 'D': n = D; break;
         case 'M': n = M; break;
         default: throw invalid_char_error; break;
      }


      // check for 3 consecutive characters at maximum
      if (n == last_number)
      {
         consecutive_char_count++;
         if (consecutive_char_count > UINT32_C(3))
         {
            throw invalid_equal_count_error;
         }
      }
      else
      {
         consecutive_char_count = UINT32_C(1);
      }


      if (n >= last_greater_number)
      {
         last_greater_number = n;
         number += n;
      }
      else if (check_alowed_order(n, last_greater_number))
      {
         if (consecutive_char_count > UINT32_C(1))
         {
            throw invalid_lesser_count_error;
         }
         else
         {
            number -= n;
         }
      }
      else
      {
         throw unkown_error;
      }

      last_number = n;
   }

   return number;
}

std::string roman_number::RomanNumber::encode(uint32_t number)
{

   std::vector<std::pair<uint32_t, std::string>> romans({ { 1000, "M" },
                                                          { 900, "CM" },
                                                          { 500, "D" },
                                                          { 400, "CD" },
                                                          { 100, "C" },
                                                          { 90, "XC" },
                                                          { 50, "L" },
                                                          { 40, "XL" },
                                                          { 10, "X" },
                                                          { 9, "IX" },
                                                          { 5, "V" },
                                                          { 4, "IV" },
                                                          { 1, "I" } });

   std::string roman = "";
   uint32_t    num   = number;
   while (num > 0)
   {
      for (auto& [ v, r ] : romans)
      {
         if (num >= v)
         {
            num -= v;
            roman += r;
            break;
         }
      }
   }
   return roman;
}

bool RomanNumber::check_alowed_order(uint32_t current, uint32_t last_greater_number)
{
   bool ret = false;
   if ((current == I) && ((last_greater_number == V) || (last_greater_number == X)))
   {
      ret = true;
   }
   else if ((current == X) && ((last_greater_number == L) || (last_greater_number == C)))
   {
      ret = true;
   }
   else if ((current == C) && ((last_greater_number == D) || (last_greater_number == M)))
   {
      ret = true;
   }
   return ret;
}


uint32_t RomanNumber::get_next_greatest(uint32_t current)
{
   uint32_t next_greatest = s_INVALID;
   uint32_t greatests[]   = { I, V, X, L, C, D, M };

   for (uint32_t n : greatests)
   {
      if (current < n)
      {
         next_greatest = n;
         break;
      }
   }
   return next_greatest;
}

}   // namespace roman_number
