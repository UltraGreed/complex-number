//
// Created by ultragreed on 1/20/24.
//

#pragma once

#include <concepts>
#include <iostream>

template<typename T> requires std::integral<T> || std::floating_point<T>
class ComplexNumber {
public:
    explicit ComplexNumber(T a = 0, T b = 0, bool isPolar = false) noexcept;

    ComplexNumber(ComplexNumber<T> const &other) noexcept;

    ComplexNumber(ComplexNumber<T> &&other) noexcept;

    ComplexNumber& operator=(ComplexNumber<T> const &other) noexcept;

    ComplexNumber& operator=(ComplexNumber<T> &&other) noexcept;

    T getReal() const noexcept;

    T getImag() const noexcept;

    void setReal(T newReal) noexcept;

    void setImag(T newImag) noexcept;

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

    auto getLength();

    auto getArg();

private:
    double EPSILON = 0.0001;

    T real;
    T imag;

    double is_no_length = true;
    double is_no_arg = true;

    double length = 0;
    double arg = 0;
};

template<typename T>
requires std::integral<T> || std::floating_point<T>
std::ostream& operator<<(std::ostream &os, const ComplexNumber<T> &cn);

#include "ComplexNumber.tpp"
