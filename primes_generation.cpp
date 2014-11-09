#include "primes_generation.h"

#include <boost/dynamic_bitset.hpp>

#include <vector>

Bitset sievePrimes(uint32_t last) {
    Bitset isPrime(last + 1);
    isPrime.set();
    isPrime.reset(0);
    isPrime.reset(1);
    uint32_t root = std::sqrt(last + 0.5);
    for (uint32_t p = 2; p <= root; ++p) {
        if (!isPrime.test(p)) {
            continue;
        }
        for (
                uint32_t nonPrime = p * p;
                p <= nonPrime && nonPrime <= last; // overflow => stop
                nonPrime += p) {
            isPrime.reset(nonPrime);
        }
    }
    return isPrime;
}

std::vector<uint32_t> findPrimes(const Bitset& isPrime) {
    std::vector<uint32_t> primes;
    for (
            size_t p = isPrime.find_first();
            p != Bitset::npos;
            p = isPrime.find_next(p)) {
        primes.push_back(p);
    }
    return primes;
}

std::vector<uint32_t> findPrimes(uint32_t last) {
    return findPrimes(sievePrimes(last));
}

std::vector<uint32_t> findMinPrimeDivisor(uint32_t last) {
    std::vector<uint32_t> minPrimeDivisor(last + 1);
    std::iota(minPrimeDivisor.begin(), minPrimeDivisor.end(), 0);
    uint32_t root = std::sqrt(last + 0.5);
    for (uint32_t p = 2; p <= root; ++p) {
        if (minPrimeDivisor[p] != p) {
            continue;
        }
        for (
                uint32_t multiple = p * p;
                p <= multiple && multiple <= last; // overflow => stop
                multiple += p) {
            if (minPrimeDivisor[multiple] == multiple) {
                minPrimeDivisor[multiple] = p;
            }
        }
    }
    return minPrimeDivisor;
}
