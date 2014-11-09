#pragma once

#include <boost/dynamic_bitset.hpp>

#include <utility>

typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int, int> pii;
typedef std::pair<ll, ll> pll;
typedef boost::dynamic_bitset<> Bitset;
//typedef pii PrimePower;

struct PrimePower {
    PrimePower(uint32_t prime, uint32_t power) : prime(prime), power(power) {}
    uint32_t prime;
    uint32_t power;
};
