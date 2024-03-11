#include "trie.hh"

#include <gtest/gtest.h>

TEST(TrieTest, TrieNodeTest) {
    // Test that we can access element 'z'.
    const TrieNode *node = new TrieNode();
    EXPECT_EQ(node->children['z'-'a'], nullptr);
}

TEST(TrieTest, BasicTest) {
    EXPECT_TRUE(true);
}