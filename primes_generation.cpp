#include "primes_generation.h"

#include <boost/dynamic_bitset.hpp>

#include <vector>

Bitset sieve(size_t last) {
    Bitset isPrime(last + 1);
    isPrime.set();
    isPrime.reset(0);
    isPrime.reset(1);
    for (size_t p = 2; p * p <= last; ++p) {
        if (!isPrime.test(p)) {
            continue;
        }
        for (size_t nonPrime = 2 * p; nonPrime <= last; nonPrime += p) {
            isPrime.reset(nonPrime);
        }
    }
    return isPrime;
}

std::vector<int> findPrimes(const Bitset& isPrime) {
    std::vector<int> primes;
    for (
            size_t p = isPrime.find_first();
            p != Bitset::npos;
            p = isPrime.find_next(p)) {
        primes.push_back(p);
    }
    return primes;
}

std::vector<int> findPrimes(uint32_t last) {
    return findPrimes(sieve(last));
}
