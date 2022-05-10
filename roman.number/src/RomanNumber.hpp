//////////////////////////////////////////////////////////////////////
/// @file  RomanNumber.hpp
/// @author jb090979@web.de
/// Copyright (c) 2022 by Jens Baumann
/// License:  Give me chocolate and you can use the code :-)
//////////////////////////////////////////////////////////////////////

#ifndef ROMAN_RomanNumber_ROMAN_RomanNumber_HPP
#define ROMAN_RomanNumber_ROMAN_RomanNumber_HPP

#include <stdint.h>
#include <string>
#include <type_traits>
#include <iostream>

namespace roman_number {

/**
  @brief This class act like an interger but uses roman numbers instead of arabic ones.
         roman numbers ranges from 1 to 3999. In case of invalid roman number an exception is throw.
         This class provide the basic mathematical operation. In case of under or overflow an exception is thrown.
         Keep in mind, divison by 0 is impossible because there is no roman number with value 0.
 */
class RomanNumber
{

   friend class RomanNumberBadTests;

   public:
   RomanNumber(std::string number);
   RomanNumber() = delete;
   RomanNumber(RomanNumber const& _other);


   template <typename T>
   RomanNumber& operator=(const T& _other)
   {
      m_RomanNumber = RomanNumber(_other).m_RomanNumber;
      m_Number      = RomanNumber(_other).m_Number;
      return *this;
   }

   /**
      @brief operator +

         The operator sum the stored RomanNumber with the given addend.

      @attention In case the summation overflows the std::overflow_error exception is thrown
    */

   template <typename T>
   RomanNumber operator+(const T& _other)
   {
      uint32_t tmp = m_Number;

      tmp += RomanNumber(_other).m_Number;

      if (tmp > s_MAX_VALUE)
      {
         throw std::overflow_error("Addtition overflow occure!");
      }
      return RomanNumber(encode(tmp));
   }

   /**
      @brief operator -

         The operator sub the stored RomanNumber with the given value.

      @attention In case the substraction underflows the std::underflow_error exception is thrown
    */
   template <typename T>
   RomanNumber operator-(const T& _other)
   {
      uint32_t tmp = m_Number;

      tmp -= RomanNumber(_other).m_Number;

      if ((tmp > m_Number) || (tmp == 0))
      {
         throw std::underflow_error("Substraction underflow occure!");
      }
      return RomanNumber(encode(tmp));
   }

   template <typename T>
   RomanNumber operator-=(const T& _other)
   {
      *this = *this - RomanNumber(_other);
      return *this;
   }


   /**
      @brief operator *

         The operator sub the stored RomanNumber with the given value.

      @attention In case the multiplication overflows then a std::overflow_error exception is thrown
    */
   template <typename T>
   RomanNumber operator*(const T& _other)
   {
      uint32_t tmp = m_Number;

      tmp *= RomanNumber(_other).m_Number;

      if (tmp > s_MAX_VALUE)
      {
         throw std::overflow_error("Multiplication overflow occure!");
      }
      return RomanNumber(encode(tmp));
   }

   template <typename T>
   RomanNumber operator*=(const T& _other)
   {
      *this = (*this) * RomanNumber(_other);
      return *this;
   }


   /**
      @brief operator /

         The operator divide the stored RomanNumber with the given value.

      @attention In case the divison underflowsn a std::underflow_error exception is thrown
      @attention The remainder is ignored,m no rounding
    */
   template <typename T>
   RomanNumber operator/(const T& _other)
   {
      RomanNumber o(_other);
      uint32_t tmp = m_Number;
      tmp /= o.m_Number;

      if (tmp == UINT32_C(0))
      {
         throw std::underflow_error("Divison underflow occure!");
      }
      return RomanNumber(encode(tmp));
   }

   template <typename T>
   RomanNumber operator/=(const T& _other)
   {
      *this = (*this) / RomanNumber(_other);
      return *this;
   }

   template <typename T>
   RomanNumber& operator+=(const T& _other)
   {
      uint32_t tmp = m_Number;

      tmp += RomanNumber(_other).m_Number;

      if (tmp <= s_MAX_VALUE)
      {
         m_Number      = tmp;
         m_RomanNumber = encode(tmp);
      }
      else
      {
         throw std::overflow_error("Addtition overflow occure!");
      }
      return *this;
   }

   template <typename T>
   bool operator==(const T& _other)
   {
      bool ret = false;

      // there is no need to cehck for the m_RomanNumber
      // both member respresent the same number
      if (m_Number == RomanNumber(_other).m_Number)
         ret = true;

      return ret;
   }





   operator uint32_t() const
   {
      return m_Number;
   }


   template <typename T>
   bool operator>(const T& _other)
   {
      return m_Number > RomanNumber(_other).m_Number;
   }

   template <typename T>
   bool operator>=(const T& _other)
   {
      return m_Number >= RomanNumber(_other).m_Number;
   }

   template <typename T>
   bool operator<=(const T& _other)
   {
      return m_Number <= RomanNumber(_other).m_Number;
   }

   template <typename T>
   bool operator<(const T& _other)
   {
      return m_Number < RomanNumber(_other).m_Number;
   }


   uint32_t convertToArabic();
   virtual ~RomanNumber();

   private:
   uint32_t              m_Number;
   std::string           m_RomanNumber;
   static const uint32_t s_MAX_VALUE = UINT32_C(3999);
   static const uint32_t s_MIN_VALUE = UINT32_C(1);
   static const uint32_t I           = UINT32_C(1);
   static const uint32_t V           = UINT32_C(5);
   static const uint32_t X           = UINT32_C(10);
   static const uint32_t L           = UINT32_C(50);
   static const uint32_t C           = UINT32_C(100);
   static const uint32_t D           = UINT32_C(500);
   static const uint32_t M           = UINT32_C(1000);
   static const uint32_t s_INVALID   = UINT32_C(4000);

   uint32_t    decode(std::string roman_number);
   std::string encode(uint32_t number);
   bool        check_alowed_order(uint32_t current, uint32_t last_greater_number);
   uint32_t    get_next_greatest(uint32_t current);
};

}   // namespace roman_number

#endif
