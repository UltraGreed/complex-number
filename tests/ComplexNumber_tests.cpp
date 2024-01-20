#include "gtest/gtest.h"
#include "ComplexNumber.h"

TEST(CreationTests, CreationTest) {
    ComplexNumber<int> number1;
    ComplexNumber<float> number2;
    ComplexNumber<double> number3;
    ComplexNumber<long long> number4;
}

TEST(CreationTests, CreationTest2) {
    ComplexNumber<int> number1(1, 2);
    ComplexNumber<float> number2(1.0, 2.0);
    ComplexNumber<double> number3(1.0, 2.0);
    ComplexNumber<long long> number4(1, 2);
}

TEST(AritmeticTests, AdditionTest) {
    ComplexNumber<int> number1(1, 2);
    ComplexNumber<int> number2(3, 4);
    ComplexNumber<int> number3 = number1 + number2;
    ASSERT_EQ(number3.real, 4);
    ASSERT_EQ(number3.imag, 6);
}

TEST(AritmeticTests, SubstractionTest) {
    ComplexNumber<int> number1(1, 2);
    ComplexNumber<int> number2(3, 4);
    ComplexNumber<int> number3 = number1 - number2;
    ASSERT_EQ(number3.real, -2);
    ASSERT_EQ(number3.imag, -2);
}

TEST(AritmeticTests, MultiplicationTest) {
    ComplexNumber<int> number1(1, 2);
    ComplexNumber<int> number2(3, 4);
    ComplexNumber<int> number3 = number1 * number2;
    ASSERT_EQ(number3.real, -5);
    ASSERT_EQ(number3.imag, 10);
}

TEST(AritmeticTests, DivisionTestInt) {
    ComplexNumber<int> number1(1, 2);
    ComplexNumber<int> number2(3, 4);
    ComplexNumber<int> number3 = number1 / number2;
    ASSERT_EQ(number3.real, 0);
    ASSERT_EQ(number3.imag, 0);
}
TEST(AritmeticTests, DivisionTestFloat) {
    ComplexNumber<float> number1(1.0, 2.0);
    ComplexNumber<float> number2(3.0, 4.0);
    ComplexNumber<float> number3 = number1 / number2;
    ASSERT_EQ(number3.real, 0.44);
    ASSERT_EQ(number3.imag, 0.08);
}

TEST(AritmeticAssignmentTests, AdditionAssignmentTest) {
    ComplexNumber<int> number1(1, 2);
    ComplexNumber<int> number2(3, 4);
    number1 += number2;
    ASSERT_EQ(number1.real, 4);
    ASSERT_EQ(number1.imag, 6);
}
TEST(AritmeticAssignmentTests, SubstractionAssignmentTest) {
    ComplexNumber<int> number1(1, 2);
    ComplexNumber<int> number2(3, 4);
    number1 -= number2;
    ASSERT_EQ(number1.real, -2);
    ASSERT_EQ(number1.imag, -2);
}

TEST(AritmeticAssignmentTests, MultiplicationAssignmentTest) {
    ComplexNumber<int> number1(1, 2);
    ComplexNumber<int> number2(3, 4);
    number1 *= number2;
    ASSERT_EQ(number1.real, -5);
    ASSERT_EQ(number1.imag, 10);
}

TEST(AritmeticAssignmentTests, DivisionAssignmentTestInt) {
    ComplexNumber<int> number1(1, 2);
    ComplexNumber<int> number2(3, 4);
    number1 /= number2;
    ASSERT_EQ(number1.real, 0);
    ASSERT_EQ(number1.imag, 0);
}

TEST(PowerTests, PowerTestInt) {
    ComplexNumber<int> number1(1, 2);
    ComplexNumber<int> number2 = number1 ^ 2;
    ASSERT_EQ(number2.real, -3);
    ASSERT_EQ(number2.imag, 4);
}

TEST(PowerTests, PowerTestFloat) {
    ComplexNumber<float> number1(1.0, 2.0);
    ComplexNumber<float> number2 = number1 ^ 2;
    ASSERT_EQ(number2.real, -3.0);
    ASSERT_EQ(number2.imag, 4.0);
}

TEST(PowerAssignmentTests, PowerAssignmentTestInt) {
    ComplexNumber<int> number1(1, 2);
    number1 ^= 2;
    ASSERT_EQ(number1.real, -3);
    ASSERT_EQ(number1.imag, 4);
}

TEST(PowerAssignmentTests, PowerAssignmentTestFloat) {
    ComplexNumber<float> number1(1.0, 2.0);
    number1 ^= 2;
    ASSERT_EQ(number1.real, -3.0);
    ASSERT_EQ(number1.imag, 4.0);
}

TEST(EqualityTests, EqualityTestInt) {
    ComplexNumber<int> number1(1, 2);
    ComplexNumber<int> number2(1, 2);
    ASSERT_TRUE(number1 == number2);
}

TEST(EqualityTests, EqualityTestInt2) {
    ComplexNumber<int> number1(1, 2);
    ComplexNumber<int> number2(3, 4);
    ASSERT_FALSE(number1 == number2);
}

TEST(EqualityTests, EqualityTestFloat) {
    ComplexNumber<float> number1(1.0, 2.0);
    ComplexNumber<float> number2(1.0, 2.0);
    ASSERT_TRUE(number1 == number2);
}

TEST(EqualityTests, EqualityTestFloat2) {
    ComplexNumber<float> number1(1.0, 2.0);
    ComplexNumber<float> number2(3.0, 4.0);
    ASSERT_FALSE(number1 == number2);
}

TEST(EqualityTests, EqualityTestDouble) {
    ComplexNumber<double> number1(1.0, 2.0);
    ComplexNumber<double> number2(1.0, 2.0);
    ASSERT_TRUE(number1 == number2);
}

TEST(EqualityTests, EqualityTestDouble2) {
    ComplexNumber<double> number1(1.0, 2.0);
    ComplexNumber<double> number2(3.0, 4.0);
    ASSERT_FALSE(number1 == number2);
}

TEST(LengthTests, LengthTestInt) {
    ComplexNumber<int> number1(1, 2);
    ASSERT_EQ(number1.length(), 2.23606797749979);
}

TEST(LengthTests, LengthTestFloat) {
    ComplexNumber<float> number1(1.0, 2.0);
    ASSERT_EQ(number1.length(), 2.236068);
}

TEST(ConsoleOutputTests, ConsoleOutputTestInt) {
    ComplexNumber<int> number1(1, 2);
    std::stringstream ss;
    ss << number1;
    ASSERT_EQ(ss.str(), "1 + 2i");
}

TEST(ConsoleOutputTests, ConsoleOutputTestFloat) {
    ComplexNumber<float> number1(1.0, 2.0);
    std::stringstream ss;
    ss << number1;
    ASSERT_EQ(ss.str(), "1.00 + 2.00i");
}