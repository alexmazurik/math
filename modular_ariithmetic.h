#pragma once

#include <cstdint>
#include <cassert>

namespace modular_arithmetic {

template <class Integer = int64_t>
Integer getReminder(Integer value, Integer modulo) {
    if (value >= modulo || value < 0) {
        value %= modulo;
    }
    return value < 0 ? value + modulo : value;
}

template <class Integer = int64_t>
class Residue {
public:
    Residue(Integer value, Integer modulo):
        value_(getReminder(value, modulo)),
        modulo_(modulo)
    {}

    Integer value() const { return value_; }
    Residue inverse() const {
        Integer inversed, tmp;
        gcdex(value_, modulo_, inversed, tmp);
        return {inversed, modulo_};
    }

private:
    Integer value_;
    Integer modulo_;
};

template <class Int>
Residue<Int> operator+(const Residue<Int>& lhs, const Residue<Int>& rhs) {
    assert(lhs.modulo() == rhs.modulo());
    return {lhs.value() + rhs.value(), lhs.modulo()};
}

template <class Int>
Residue<Int> operator-(const Residue<Int>& lhs, const Residue<Int>& rhs) {
    assert(lhs.modulo() == rhs.modulo());
    return {lhs.value() - rhs.value(), lhs.modulo()};
}

template <class Int>
Residue<Int> operator*(const Residue<Int>& lhs, const Residue<Int>& rhs) {
    assert(lhs.modulo() == rhs.modulo());
    return {lhs.value() * rhs.value(), lhs.modulo()};
}

template <class Int>
Residue<Int> operator/(const Residue<Int>& lhs, const Residue<Int>& rhs) {
    assert(lhs.modulo() == rhs.modulo());
    assert(rhs > Int(0));
    return lhs * rhs.inverse();
}

} // namespace modular_arithmetic
