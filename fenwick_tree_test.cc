#include "fenwick_tree.hh"

#include <gtest/gtest.h>

TEST(FenwickTreeTest, FullSumTest) {
    constexpr int SIZE = 10;
    FenwickTree<int> f(SIZE);
    int exp_sum = 0;
    
    for(int i = 0; i<SIZE; ++i) {
        int val = i+1;
        exp_sum+=val;
        f.add(i, val);
    }

    EXPECT_EQ(f.sum(SIZE), exp_sum);
}

TEST(FenwickTreeTest, FullSumTest2) {
    constexpr int SIZE = 10;
    FenwickTree<int> f(SIZE);
    int exp_sum = 0;
    
    for(int i = 0; i<SIZE; ++i) {
        int val = i+1;
        exp_sum+=2*val;
        f.add(i, val);
        f.add(i, val);
    }

    EXPECT_EQ(f.sum(SIZE), exp_sum);
}

TEST(FenwickTreeTest, RangeSum) {
    constexpr int SIZE = 10;
    const int start = 4;
    const int end = 8;
    FenwickTree<int> f(SIZE);
    int exp_sum = 0;
    
    for(int i = 0; i<SIZE; ++i) {
        int val = i+1;
        
        if(i>=start && i<=end) {
            exp_sum+=val;
        }
        f.add(i, val);
    }

    EXPECT_EQ(f.sum(start, end), exp_sum);
}