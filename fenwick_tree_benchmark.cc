#include <benchmark/benchmark.h>

#include "fenwick_tree.hh"

namespace {

constexpr int SIZE = 10;

}

static void BM_Add(benchmark::State &state) {
    FenwickTree<int> f(SIZE);

    for(auto _ : state) {
        for(int i = 0; i<SIZE; ++i) {
            int val = i+1;
            f.add(i, val);
        }
    }
}

static void BM_FullRangeSum(benchmark::State &state) {
    FenwickTree<int> f(SIZE);
    for(int i = 0; i<SIZE; ++i) {
        int val = i+1;
        f.add(i, val);
    }

    for(auto _ : state) {
        f.sum(SIZE);
    }
}

static void BM_RangeSum(benchmark::State &state) {
    FenwickTree<int> f(SIZE);
    for(int i = 0; i<SIZE; ++i) {
        int val = i+1;
        f.add(i, val);
    }

    for(auto _ : state) {
        f.sum(SIZE/2, SIZE);
    }
}

BENCHMARK(BM_Add);
BENCHMARK(BM_FullRangeSum);
BENCHMARK(BM_RangeSum);

BENCHMARK_MAIN();