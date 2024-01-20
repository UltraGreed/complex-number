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

TEST(ArithmeticTests, AdditionTest) {
    ComplexNumber<int> number1(1, 2);
    ComplexNumber<int> number2(3, 4);
    ComplexNumber<int> number3 = number1 + number2;
    ASSERT_EQ(number3.getReal(), 4);
    ASSERT_EQ(number3.getImag(), 6);
}

TEST(ArithmeticTests, SubstractionTest) {
    ComplexNumber<int> number1(1, 2);
    ComplexNumber<int> number2(3, 4);
    ComplexNumber<int> number3 = number1 - number2;
    ASSERT_EQ(number3.getReal(), -2);
    ASSERT_EQ(number3.getImag(), -2);
}

TEST(ArithmeticTests, MultiplicationTest) {
    ComplexNumber<int> number1(1, 2);
    ComplexNumber<int> number2(3, 4);
    ComplexNumber<int> number3 = number1 * number2;
    ASSERT_EQ(number3.getReal(), -5);
    ASSERT_EQ(number3.getImag(), 10);
}

TEST(ArithmeticTests, DivisionTestInt) {
    ComplexNumber<int> number1(1, 2);
    ComplexNumber<int> number2(3, 4);
    ComplexNumber<int> number3 = number1 / number2;
    ASSERT_EQ(number3.getReal(), 0);
    ASSERT_EQ(number3.getImag(), 0);
}
TEST(ArithmeticTests, DivisionTestFloat) {
    ComplexNumber<float> number1(1.0, 2.0);
    ComplexNumber<float> number2(3.0, 4.0);
    ComplexNumber<float> number3 = number1 / number2;
    EXPECT_NEAR(number3.getReal(), 0.44, 0.0001);
    EXPECT_NEAR(number3.getImag(), 0.08, 0.0001);
}

TEST(ArithmeticAssignmentTests, AdditionAssignmentTest) {
    ComplexNumber<int> number1(1, 2);
    ComplexNumber<int> number2(3, 4);
    number1 += number2;
    ASSERT_EQ(number1.getReal(), 4);
    ASSERT_EQ(number1.getImag(), 6);
}
TEST(ArithmeticAssignmentTests, SubstractionAssignmentTest) {
    ComplexNumber<int> number1(1, 2);
    ComplexNumber<int> number2(3, 4);
    number1 -= number2;
    ASSERT_EQ(number1.getReal(), -2);
    ASSERT_EQ(number1.getImag(), -2);
}

TEST(ArithmeticAssignmentTests, MultiplicationAssignmentTest) {
    ComplexNumber<int> number1(1, 2);
    ComplexNumber<int> number2(3, 4);
    number1 *= number2;
    ASSERT_EQ(number1.getReal(), -5);
    ASSERT_EQ(number1.getImag(), 10);
}

TEST(ArithmeticAssignmentTests, DivisionAssignmentTestInt) {
    ComplexNumber<int> number1(1, 2);
    ComplexNumber<int> number2(3, 4);
    number1 /= number2;
    ASSERT_EQ(number1.getReal(), 0);
    ASSERT_EQ(number1.getImag(), 0);
}

TEST(PowerTests, PowerTestInt) {
    ComplexNumber<int> number1(1, 2);
    ComplexNumber<int> number2 = number1 ^ 2;
    ASSERT_EQ(number2.getReal(), -3);
    ASSERT_EQ(number2.getImag(), 4);
}

TEST(PowerTests, PowerTestFloat) {
    ComplexNumber<float> number1(1.0, 2.0);
    ComplexNumber<float> number2 = number1 ^ 2;
    ASSERT_EQ(number2.getReal(), -3.0);
    ASSERT_EQ(number2.getImag(), 4.0);
}

TEST(PowerAssignmentTests, PowerAssignmentTestInt) {
    ComplexNumber<int> number1(1, 2);
    number1 ^= 2;
    ASSERT_EQ(number1.getReal(), -3);
    ASSERT_EQ(number1.getImag(), 4);
}

TEST(PowerAssignmentTests, PowerAssignmentTestFloat) {
    ComplexNumber<float> number1(1.0, 2.0);
    number1 ^= 2;
    ASSERT_EQ(number1.getReal(), -3.0);
    ASSERT_EQ(number1.getImag(), 4.0);
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
    EXPECT_NEAR(number1.getLength(), 2.23606797749979, 0.0001);
}

TEST(LengthTests, LengthTestFloat) {
    ComplexNumber<float> number1(1.0, 2.0);
    EXPECT_NEAR(number1.getLength(), 2.23606797749979, 0.0001);
}

TEST(ConsoleOutputTests, ConsoleOutputTestInt) {
    ComplexNumber<int> number1(1, 2);
    std::stringstream ss;
    ss << number1;
    ASSERT_EQ(ss.str(), "1 + 2i");
}

TEST(ConsoleOutputTests, ConsoleOutputTestFloat) {
    ComplexNumber<float> number1(1.11, 2.24);
    std::stringstream ss;
    ss << number1;
    ASSERT_EQ(ss.str(), "1.11 + 2.24i");
}
