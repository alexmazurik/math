#pragma once

#include <cstdint>
#include <cassert>

namespace internal {
template <class Policy>
class EquivalenceClass;
template <int64_t Modulo, class Integer = int64_t>
FixedModuloReminder<Modulo, Integer> operator+(
        const FixedModuloReminder<Modulo, Integer>& lhs,
        const FixedModuloReminder<Modulo, Integer>& rhs) {
    FixedModuloReminder<Modulo, Integer> res(lhs);
    res.setValue(getReminder(lhs.value() + rhs.value()));
    return res;
}

template <int64_t Modulo, class Integer = int64_t>
FixedModuloReminder<Modulo, Integer> operator-(
        const FixedModuloReminder<Modulo, Integer>& lhs,
        const FixedModuloReminder<Modulo, Integer>& rhs) {
    FixedModuloReminder<Modulo, Integer> res(lhs);
    res.setValue(getReminder(lhs.value() - rhs.value()));
    return res;
}

template <int64_t Modulo, class Integer = int64_t>
FixedModuloReminder<Modulo, Integer> operator*(
        const FixedModuloReminder<Modulo, Integer>& lhs,
        const FixedModuloReminder<Modulo, Integer>& rhs) {
    FixedModuloReminder<Modulo, Integer> res(lhs);
    res.setValue(getReminder(lhs.value() * rhs.value()));
    return res;
}

} // namespace internal


template <class Integer = int64_t>
Integer getReminder(Integer value, Integer modulo) {
    if (value >= modulo || value < 0) {
        value %= modulo;
    }
    return value < 0 ? value + modulo : value;
}

template <int64_t Modulo, class Integer = int64_t>
class FixedModuloReminder {
public:
    FixedModuloReminder(Integer value) : modulo_(Modulo) {
        assert(modulo_ > 0);
        setValue(value);
    }

    void setValue(Integer value) { value_ = getReminder(value, modulo_); }
private:
    Integer value_;
    Integer modulo_;
};

template <class Integer>
class FixedModuloReminder<0, Integer> {
public:
    FixedModuloReminder(Integer value, Integer modulo) : modulo_(modulo) {
        assert(modulo_ > 0);
        setValue(value);
    }
    void setValue(Integer value) { value_ = getReminder(value, modulo_); }
    Integer value() const { return value_; }

private:
    Integer value_;
    Integer modulo_;
};

template <class Integer>
using ModuloReminder = FixedModuloReminder<0, Integer>;

