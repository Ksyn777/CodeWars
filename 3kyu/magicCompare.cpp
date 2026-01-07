#include <iostream>
#include <cmath>

template <typename T>
class ComparisonChain {
    bool status;
    T last_value;

public:
    ComparisonChain(bool s, T v) : status(s), last_value(v) {}

    operator bool() const {
        return status;
    }

    template <typename U>
    ComparisonChain<T> operator<(const U& next) const {
        return ComparisonChain<T>(status && (last_value < static_cast<T>(next)), static_cast<T>(next));
    }

    template <typename U>
    ComparisonChain<T> operator>(const U& next) const {
        return ComparisonChain<T>(status && (last_value > static_cast<T>(next)), static_cast<T>(next));
    }

    template <typename U>
    ComparisonChain<T> operator<=(const U& next) const {
        return ComparisonChain<T>(status && (last_value <= static_cast<T>(next)), static_cast<T>(next));
    }

    template <typename U>
    ComparisonChain<T> operator>=(const U& next) const {
        return ComparisonChain<T>(status && (last_value >= static_cast<T>(next)), static_cast<T>(next));
    }

    template <typename U>
    ComparisonChain<T> operator==(const U& next) const {
        return ComparisonChain<T>(status && (last_value == static_cast<T>(next)), static_cast<T>(next));
    }

    template <typename U>
    ComparisonChain<T> operator!=(const U& next) const {
        return ComparisonChain<T>(status && (last_value != static_cast<T>(next)), static_cast<T>(next));
    }
};

template <typename T>
class MagicCompare {
    T value;

public:
    MagicCompare(T v = T()) : value(v) {}

    operator T&() { return value; }
    operator const T&() const { return value; }

    MagicCompare& operator++() {
        ++value;
        return *this;
    }

    MagicCompare operator++(int) {
        MagicCompare temp = *this;
        ++value;
        return temp;
    }

    MagicCompare& operator+=(const T& other) {
        value += other;
        return *this;
    }

    MagicCompare operator*(const MagicCompare& o) const { return MagicCompare(value * o.value); }
    MagicCompare operator+(const MagicCompare& o) const { return MagicCompare(value + o.value); }
    MagicCompare operator-(const MagicCompare& o) const { return MagicCompare(value - o.value); }

    template <typename U>
    ComparisonChain<T> operator<(const U& o) const {
        return ComparisonChain<T>(value < static_cast<T>(o), static_cast<T>(o));
    }

    template <typename U>
    ComparisonChain<T> operator>(const U& o) const {
        return ComparisonChain<T>(value > static_cast<T>(o), static_cast<T>(o));
    }

    template <typename U>
    ComparisonChain<T> operator<=(const U& o) const {
        return ComparisonChain<T>(value <= static_cast<T>(o), static_cast<T>(o));
    }

    template <typename U>
    ComparisonChain<T> operator>=(const U& o) const {
        return ComparisonChain<T>(value >= static_cast<T>(o), static_cast<T>(o));
    }

    template <typename U>
    ComparisonChain<T> operator==(const U& o) const {
        return ComparisonChain<T>(value == static_cast<T>(o), static_cast<T>(o));
    }

    template <typename U>
    ComparisonChain<T> operator!=(const U& o) const {
        return ComparisonChain<T>(value != static_cast<T>(o), static_cast<T>(o));
    }

    friend ComparisonChain<T> operator<(const T& l, const MagicCompare& r) {
        return ComparisonChain<T>(l < r.value, r.value);
    }

    friend ComparisonChain<T> operator>(const T& l, const MagicCompare& r) {
        return ComparisonChain<T>(l > r.value, r.value);
    }

    friend ComparisonChain<T> operator<=(const T& l, const MagicCompare& r) {
        return ComparisonChain<T>(l <= r.value, r.value);
    }

    friend ComparisonChain<T> operator>=(const T& l, const MagicCompare& r) {
        return ComparisonChain<T>(l >= r.value, r.value);
    }

    friend ComparisonChain<T> operator==(const T& l, const MagicCompare& r) {
        return ComparisonChain<T>(l == r.value, r.value);
    }

    friend ComparisonChain<T> operator!=(const T& l, const MagicCompare& r) {
        return ComparisonChain<T>(l != r.value, r.value);
    }

    friend MagicCompare operator*(const T& l, const MagicCompare& r) {
        return MagicCompare(l * r.value);
    }

    friend MagicCompare operator*(const MagicCompare& l, const T& r) {
        return MagicCompare(l.value * r);
    }

    friend std::ostream& operator<<(std::ostream& os, const MagicCompare& mc) {
        return os << mc.value;
    }
};