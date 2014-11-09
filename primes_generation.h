#pragma once

#include "defs.h"

#include <boost/dynamic_bitset.hpp>

#include <vector>

Bitset sievePrimes(uint32_t last);

std::vector<uint32_t> findPrimes(const Bitset& isPrime);
std::vector<uint32_t> findPrimes(uint32_t last);

std::vector<uint32_t> findMinPrimeDivisor(uint32_t last);

class PreprocessFactorizator {
public:
    explicit PreprocessFactorizator(
            const std::vector<uint32_t>& minPrimeDivisor) :
        minPrimeDivisor_(minPrimeDivisor)
    {}
    explicit PreprocessFactorizator(std::vector<uint32_t>&& minPrimeDivisor) :
        minPrimeDivisor_(std::move(minPrimeDivisor))
    {}

    std::vector<PrimePower> factor(uint32_t n) {
        std::vector<PrimePower> factorization;
        while (n != 1) {
            uint32_t prime = minPrimeDivisor_[n];
            uint8_t power = 0;
            for (; minPrimeDivisor_[n] == prime; n /= prime) {
                ++power;
            }
            factorization.emplace_back(prime, power);
        }
        factorization.shrink_to_fit();
        return factorization;
    }

private:
    std::vector<uint32_t> minPrimeDivisor_;
};
