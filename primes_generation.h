#pragma once

#include <boost/dynamic_bitset.hpp>

#include <vector>

typedef boost::dynamic_bitset<> Bitset;

Bitset sieve(size_t last);

std::vector<int> findPrimes(const Bitset& isPrime);
std::vector<int> findPrimes(size_t last);
