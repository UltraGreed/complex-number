//
// Created by ultragreed on 1/20/24.
//

#pragma once

#include <concepts>
#include <iostream>

template<typename T> requires std::integral<T> || std::floating_point<T>
class ComplexNumber {
public:
    T real;
    T imag;

    ComplexNumber(T real = 0, T imag = 0);

    auto operator+(ComplexNumber<T> &other);

    void operator+=(ComplexNumber<T> &other);

    auto operator-(ComplexNumber<T> &other);

    void operator-=(ComplexNumber<T> &other);

    auto operator*(ComplexNumber<T> &other);

    void operator*=(ComplexNumber<T> &other);

    auto operator/(ComplexNumber<T> &other);

    void operator/=(ComplexNumber<T> &other);

    auto operator^(int exponent);

    void operator^=(int exponent);

    auto operator==(ComplexNumber<T> &other);

    float length();

    auto operator<<(std::ostream& os);
private:
    double epsilon = 0.0001;
};
