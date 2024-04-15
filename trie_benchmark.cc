#include <benchmark/benchmark.h>

#include "trie.hh"

namespace {

constexpr int REPEAT_FACTOR = 5;

}

static void BM_BasicAdd(benchmark::State &state) {
    Trie trie;
    std::string str;
    for(auto _ : state) {
        for(char c = 'a'; c<='z'; ++c) {
            str+=c;
            trie.add(str);
        }
    }
}

static void BM_BasicRemove(benchmark::State &state) {
    Trie trie;
    std::string str;
    for(char c = 'a'; c<='z'; ++c) {
        for(int i = 0; i<REPEAT_FACTOR; ++i) {
            str+=c;
        }
    }
    std::string new_str = str + "abc";
    trie.add(str);
    for(auto _ : state) {
        trie.remove(str);
        trie.remove(new_str);
    }
}

static void BM_BasicFind(benchmark::State &state) {
    Trie trie;
    std::string str;
    for(char c = 'a'; c<='z'; ++c) {
        for(int i = 0; i<REPEAT_FACTOR; ++i) {
            str+=c;
        }
    }
    std::string new_str = str + "abc";
    trie.add(str);
    for(auto _ : state) {
        trie.find(str);
        trie.find(new_str);
    }
}

BENCHMARK(BM_BasicAdd);
BENCHMARK(BM_BasicRemove);
BENCHMARK(BM_BasicFind);

BENCHMARK_MAIN();