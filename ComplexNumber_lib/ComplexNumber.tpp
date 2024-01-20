//
// Created by ultragreed on 1/20/24.
//
#pragma once

#include <cmath>

template<typename T>
requires std::integral<T> || std::floating_point<T>
ComplexNumber<T>::ComplexNumber(T a, T b, bool isPolar) noexcept {
    if (!isPolar) {
        this->real = a;
        this->imag = b;
    } else {
        length = a;
        arg = b;

        is_no_length = false;
        is_no_arg = false;

        this->real = std::cos(arg) * length;
        this->imag = std::sin(arg) * length;
    }
}

template<typename T>
requires std::integral<T> || std::floating_point<T>
ComplexNumber<T>::ComplexNumber(ComplexNumber<T> const &other) noexcept {
    this->real = other.real;
    this->imag = other.imag;

    this->is_no_length = true;
    this->is_no_arg = true;
}

template<typename T>
requires std::integral<T> || std::floating_point<T>
ComplexNumber<T>::ComplexNumber(ComplexNumber<T> &&other) noexcept {
    this->real = std::move(other.real);
    this->imag = std::move(other.imag);

    this->is_no_length = true;
    this->is_no_arg = true;
}

template<typename T>
requires std::integral<T> || std::floating_point<T>
ComplexNumber<T> &ComplexNumber<T>::operator=(ComplexNumber<T> const &other) noexcept {
    this->real = other.real;
    this->imag = other.imag;

    this->is_no_length = true;
    this->is_no_arg = true;

    return *this;
}

template<typename T>
requires std::integral<T> || std::floating_point<T>
ComplexNumber<T> &ComplexNumber<T>::operator=(ComplexNumber<T> &&other) noexcept {
    this->real = other.real;
    this->imag = other.imag;

    this->is_no_length = true;
    this->is_no_arg = true;

    return *this;
}

template<typename T>
requires std::integral<T> || std::floating_point<T>
T ComplexNumber<T>::getReal() const noexcept {
    return this->real;
}

template<typename T>
requires std::integral<T> || std::floating_point<T>
T ComplexNumber<T>::getImag() const noexcept {
    return this->imag;
}

template<typename T>
requires std::integral<T> || std::floating_point<T>
void ComplexNumber<T>::setReal(T newReal) noexcept {
    this->real = newReal;
    this->is_no_length = true;
    this->is_no_arg = true;
}

template<typename T>
requires std::integral<T> || std::floating_point<T>
void ComplexNumber<T>::setImag(T newImag) noexcept {
    this->imag = newImag;
    this->is_no_length = true;
    this->is_no_arg = true;
}

template<typename T>
requires std::integral<T> || std::floating_point<T>
auto ComplexNumber<T>::operator+(ComplexNumber<T> &other) {
    return ComplexNumber<T>(this->real + other.real, this->imag + other.imag);
}

template<typename T>
requires std::integral<T> || std::floating_point<T>
void ComplexNumber<T>::operator+=(ComplexNumber<T> &other) {
    *this = std::move(*this + other);
}

template<typename T>
requires std::integral<T> || std::floating_point<T>
auto ComplexNumber<T>::operator-(ComplexNumber<T> &other) {
    return ComplexNumber<T>(this->real - other.real, this->imag - other.imag);
}

template<typename T>
requires std::integral<T> || std::floating_point<T>
void ComplexNumber<T>::operator-=(ComplexNumber<T> &other) {
    *this = *this - other;
}

template<typename T>
requires std::integral<T> || std::floating_point<T>
auto ComplexNumber<T>::operator*(ComplexNumber<T> &other) {
    return ComplexNumber<T>(this->real * other.real - this->imag * other.imag,
                            this->real * other.imag + this->imag * other.real);
}

template<typename T>
requires std::integral<T> || std::floating_point<T>
void ComplexNumber<T>::operator*=(ComplexNumber<T> &other) {
    *this = *this * other;
}

template<typename T>
requires std::integral<T> || std::floating_point<T>
auto ComplexNumber<T>::operator/(ComplexNumber<T> &other) {
    return ComplexNumber<T>(this->getLength() / other.getLength(), this->getArg() - other.getArg(), true);
}

template<typename T>
requires std::integral<T> || std::floating_point<T>
void ComplexNumber<T>::operator/=(ComplexNumber<T> &other) {
    *this = *this / other;
}

template<typename T>
requires std::integral<T> || std::floating_point<T>
auto ComplexNumber<T>::operator^(int exponent) {
    if (exponent == 0)
        return ComplexNumber<T>(1, 0);

    if (exponent == 1)
        return *this;

    if (exponent == 2)
        return (*this) * (*this);

    return ComplexNumber<T>(std::pow(this->getLength(), exponent), this->getArg() * exponent, true);
}

template<typename T>
requires std::integral<T> || std::floating_point<T>
void ComplexNumber<T>::operator^=(int exponent) {
    *this = *this ^ exponent;
}

template<typename T>
requires std::integral<T> || std::floating_point<T>
auto ComplexNumber<T>::operator==(ComplexNumber<T> &other) {
    return std::abs(this->real - other.getReal()) < EPSILON && std::abs(this->imag - other.getImag()) < EPSILON;
}

template<typename T>
requires std::integral<T> || std::floating_point<T>
auto ComplexNumber<T>::getLength() {
    if (this->is_no_length) {
        this->length = std::sqrt(this->real * this->real + this->imag * this->imag);
        this->is_no_length = false;
    }
    return this->length;
}

template<typename T>
requires std::integral<T> || std::floating_point<T>
auto ComplexNumber<T>::getArg() {
    if (this->is_no_arg) {
        this->arg = std::atan2(this->imag, this->real);
        this->is_no_arg = false;
    }
    return this->arg;
}

template<typename T>
requires std::integral<T> || std::floating_point<T>
std::ostream &operator<<(std::ostream &os, const ComplexNumber<T> &cn) {
    return os << cn.getReal() << " + " << cn.getImag() << "i";
}
