//////////////////////////////////////////////////////////////////////
/// @file  NumberTest.cpp
/// @author jb090979@web.de
/// Copyright (c) 2022 by Jens Baumann
/// License:  Give me chocolate and you can use the code :-)
//////////////////////////////////////////////////////////////////////

#include <gtest/gtest.h>
#include <RomanNumber.hpp>
#include <tuple>

namespace roman_number {

typedef std::tuple<uint32_t, std::string> resultPair_t;

class RomanNumberTest : public ::testing::TestWithParam<resultPair_t>
{
   protected:
   virtual void SetUp() override{};
   virtual void TearDown() override{};
};

INSTANTIATE_TEST_CASE_P(good_cases,
                        RomanNumberTest,
                        ::testing::Values(std::make_tuple(1, "I"),
                                          std::make_tuple(2, "II"),
                                          std::make_tuple(3, "III"),
                                          std::make_tuple(4, "IV"),
                                          std::make_tuple(5, "V"),
                                          std::make_tuple(6, "VI"),
                                          std::make_tuple(7, "VII"),
                                          std::make_tuple(8, "VIII"),
                                          std::make_tuple(9, "IX"),
                                          std::make_tuple(10, "X"),
                                          std::make_tuple(50, "L"),
                                          std::make_tuple(100, "C"),
                                          std::make_tuple(500, "D"),
                                          std::make_tuple(1000, "M"),
                                          std::make_tuple(4, "IV"),
                                          std::make_tuple(40, "XL"),
                                          std::make_tuple(90, "XC"),
                                          std::make_tuple(400, "CD"),
                                          std::make_tuple(900, "CM"),
                                          std::make_tuple(20, "XX"),
                                          std::make_tuple(30, "XXX"),
                                          std::make_tuple(1023, "MXXIII"),
                                          std::make_tuple(1019, "MIXX"),
                                          std::make_tuple(542, "DXLII"),
                                          std::make_tuple(19, "IXX"),
                                          std::make_tuple(3724, "MMMDCCXXIV"),
                                          std::make_tuple(3999, "MMMCMXCIX")));

TEST_P(RomanNumberTest, good_case_test)
{
   std::string n = std::get<1>(GetParam());
   RomanNumber number(n);

   uint32_t actual   = number.convertToArabic();
   uint32_t expected = std::get<0>(GetParam());
   ;
   EXPECT_EQ(actual, expected);
}


class RomanNumberBadTests : public ::testing::TestWithParam<std::string>
{
   protected:
   virtual void SetUp() override{};
   virtual void TearDown() override{};
};

INSTANTIATE_TEST_CASE_P(bad_cases,
                        RomanNumberBadTests,
                        ::testing::Values("IIII",
                                          "IIIX",
                                          "A",
                                          "B",
                                          "E",
                                          "F",
                                          "G",
                                          "H",
                                          "J",
                                          "K",
                                          "N",
                                          "O",
                                          "P",
                                          "Q",
                                          "R",
                                          "S",
                                          "T",
                                          "U",
                                          "W",
                                          "Y",
                                          "Z",
                                          "ID",
                                          "IL",
                                          "IM",
                                          "IC",
                                          "XD",
                                          "XM",
                                          "DM",
                                          "VV",
                                          "DD",
                                          "LL",
                                          "MDD",
                                          "CLL",
                                          "MVV"));


TEST_P(RomanNumberBadTests, bad_case_test)
{
   EXPECT_ANY_THROW(RomanNumber number(GetParam()));
}


TEST(RomanOperations, test_plus)
{
   RomanNumber actual("I");
   RomanNumber expected("I");

   actual += "V";
   expected = "VI";
   EXPECT_EQ(actual, expected);

   actual = "II";
   actual += RomanNumber("VIII");
   expected = "X";
   EXPECT_EQ(actual, expected);


   actual   = RomanNumber("II") + RomanNumber("X");
   expected = "XII";
   EXPECT_EQ(actual, expected);

   RomanNumber n1 = RomanNumber("III");
   RomanNumber n2 = RomanNumber("X");
   actual         = n1 + n2;
   expected       = "XIII";
   EXPECT_EQ(actual, expected);

   RomanNumber n3 = RomanNumber("III");
   actual         = n3 + std::string("III");
   expected       = "VI";
   EXPECT_EQ(actual, expected);
}

TEST(RomanOperations, test_minus)
{
   RomanNumber actual("V");
   RomanNumber expected("IV");

   actual -= "I";
   expected = "IV";
   EXPECT_EQ(actual, expected);

   actual = "VIII";
   actual -= RomanNumber("II");
   expected = "VI";
   EXPECT_EQ(actual, expected);


   actual   = RomanNumber("X") - RomanNumber("VIII");
   expected = "II";
   EXPECT_EQ(actual, expected);

   RomanNumber n1 = RomanNumber("X");
   RomanNumber n2 = RomanNumber("III");
   actual         = n1 - n2;
   expected       = "VII";
   EXPECT_EQ(actual, expected);

   RomanNumber n3 = RomanNumber("XI");
   actual         = n3 - std::string("III");
   expected       = "VIII";
   EXPECT_EQ(actual, expected);
}

TEST(RomanOperations, test_multiply)
{
   RomanNumber actual("V");
   RomanNumber expected("IV");

   actual *= "I";
   expected = "V";
   EXPECT_EQ(actual, expected);

   actual = "VIII";
   actual *= RomanNumber("II");
   expected = "XVI";
   EXPECT_EQ(actual, expected);


   actual   = RomanNumber("X") * RomanNumber("X");
   expected = "C";
   EXPECT_EQ(actual, expected);

   RomanNumber n1 = RomanNumber("X");
   RomanNumber n2 = RomanNumber("III");
   actual         = n1 * n2;
   expected       = "XXX";
   EXPECT_EQ(actual, expected);

   RomanNumber n3 = RomanNumber("X");
   actual         = n3 * std::string("V");
   expected       = "L";
   EXPECT_EQ(actual, expected);
}

TEST(RomanOperations, test_division)
{
   RomanNumber actual("V");
   RomanNumber expected("IV");

   actual /= "I";
   expected = "V";
   EXPECT_EQ(actual, expected);

   actual = "VIII";
   actual /= RomanNumber("II");
   expected = "IV";
   EXPECT_EQ(actual, expected);


   actual   = RomanNumber("X") / RomanNumber("X");
   expected = "I";
   EXPECT_EQ(actual, expected);

   RomanNumber n1 = RomanNumber("X");
   RomanNumber n2 = RomanNumber("III");
   actual         = n1 / n2;
   expected       = "III";
   EXPECT_EQ(actual, expected);

   RomanNumber n3 = RomanNumber("X");
   actual         = n3 / std::string("V");
   expected       = "II";
   EXPECT_EQ(actual, expected);
}


TEST(RomanOperations, test_roman_range)
{
   RomanNumber n("I");

   for (uint32_t expected = 2; expected <= 3999; expected++)
   {
      n += "I";
      uint32_t actual = n.convertToArabic();
      EXPECT_EQ(actual, expected);
   }
}

TEST(RomanOperations, test_sum_overflow)
{
   RomanNumber n("MMMCMXCIX");
   EXPECT_THROW(n += "I", std::overflow_error);
}

TEST(RomanOperations, test_minus_underflow)
{
   RomanNumber n("V");
   EXPECT_THROW(n -= "V", std::underflow_error); //0 underflow
   EXPECT_THROW(n -= "X", std::underflow_error); //- underflow
}


TEST(RomanOperations, test_multiply_overflow)
{
   RomanNumber n("MCCCXXXIII"); //1333
   EXPECT_NO_THROW(n * "III");
   EXPECT_THROW(n *= "IV", std::overflow_error);

   EXPECT_THROW((n * "III")+"I", std::overflow_error);
}

TEST(RomanOperations, test_divison_underflow)
{
   RomanNumber n("V");
   EXPECT_THROW(n /= "VI", std::underflow_error);
}


TEST(RomanOperations, test_boolean_exp)
{
   EXPECT_TRUE(RomanNumber("V") > RomanNumber("III"));
   EXPECT_TRUE(RomanNumber("V") > std::string("III"));
   EXPECT_TRUE(RomanNumber("V") > "III");

   EXPECT_TRUE(RomanNumber("V") >= RomanNumber("III"));
   EXPECT_TRUE(RomanNumber("V") >= std::string("III"));
   EXPECT_TRUE(RomanNumber("V") >= "V");

   EXPECT_FALSE(RomanNumber("V") <= RomanNumber("III"));
   EXPECT_FALSE(RomanNumber("V") <= std::string("III"));
   EXPECT_TRUE(RomanNumber("V") <= "V");


   EXPECT_FALSE(RomanNumber("V") < RomanNumber("III"));
   EXPECT_FALSE(RomanNumber("V") < std::string("III"));
   EXPECT_FALSE(RomanNumber("V") < "V");


   EXPECT_TRUE(RomanNumber("V") == RomanNumber("V"));
   EXPECT_FALSE(RomanNumber("V") == std::string("III"));
   EXPECT_TRUE(RomanNumber("VI") == "VI");
}


}   // namespace roman_number
