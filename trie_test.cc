#include "trie.hh"

#include <gtest/gtest.h>

TEST(TrieTest, TrieNodeTest) {
    // Test that we can access element 'z'.
    const TrieNode *node = new TrieNode();
    EXPECT_EQ(node->children['z'-'a'], nullptr);
}

TEST(TrieTest, AddBasicTest) {
    TrieNode *root = new TrieNode();
    add(root, "abcd");
    EXPECT_NE(root->children[0], nullptr);
    EXPECT_NE(root->children[0]->children[1], nullptr);
    EXPECT_NE(root->children[0]->children[1]->children[2], nullptr);
    EXPECT_NE(root->children[0]->children[1]->children[2]->children[3], nullptr);
}

TEST(TrieTest, RemoveBasicTest) {
    TrieNode *root = new TrieNode();
    add(root, "abcd");
    EXPECT_NE(root->children[0], nullptr);   
    remove(root, "abcd");
    EXPECT_EQ(root->children[0], nullptr);
}