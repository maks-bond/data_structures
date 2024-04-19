#include "segment_tree.hh"

#include <gtest/gtest.h>
#include <algorithm>

TEST(SegmentTreeTest, FullRangeTest) {
    std::vector<int> a{1, 2, 3, 4, 5};
    SegmentTree<int> f(a);
    int exp_max = *std::max_element(a.begin(), a.end());
    
    EXPECT_EQ(f.max(0, a.size()-1), exp_max);
}

TEST(SegmentTreeTest, FullRangeTest2) {
    constexpr int SIZE = 5;
    SegmentTree<int> f(SIZE);
    f.update(0, 7);
    f.update(1, 5);
    f.update(2, 3);
    f.update(3, 1);
    f.update(4, 2);
    int exp_max = 7;
    
    EXPECT_EQ(f.max(0, SIZE-1), exp_max);
}

TEST(SegmentTreeTest, PartialRangeTest) {
    std::vector<int> a{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    SegmentTree<int> f(a);
    int exp_max = *std::max_element(a.begin()+2, a.end()-2);
    
    EXPECT_EQ(f.max(2, a.size()-3), exp_max);
}

TEST(SegmentTreeTest, PartialRangeTest2) {
    constexpr int SIZE = 5;
    SegmentTree<int> f(SIZE);
    f.update(0, 7);
    f.update(1, 5);
    f.update(2, 3);
    f.update(3, 1);
    f.update(4, 2);
    int exp_max = 5;
    
    EXPECT_EQ(f.max(1, 3), exp_max);
}