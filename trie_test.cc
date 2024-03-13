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

TEST(TrieTest, FindBasicTest) {
    TrieNode *root = new TrieNode();
    add(root, "abcd");

    EXPECT_TRUE(find(root, "abcd"));
    EXPECT_TRUE(find(root, "abc"));
    EXPECT_TRUE(find(root, "ab"));
    EXPECT_TRUE(find(root, "a"));
    EXPECT_FALSE(find(root, "bcd"));
}

TEST(TrieTest, RemoveTest) {
    TrieNode *root = new TrieNode();
    add(root, "abcd");
    add(root, "abc");
    add(root, "ab");
    add(root, "a");
    EXPECT_TRUE(find(root, "abcd"));

    remove(root, "abcd");
    EXPECT_FALSE(find(root, "abcd"));
    EXPECT_TRUE(find(root, "abc"));

    remove(root, "abc");
    EXPECT_FALSE(find(root, "abc"));
    EXPECT_TRUE(find(root, "ab"));

    remove(root, "ab");
    EXPECT_FALSE(find(root, "ab"));
    EXPECT_TRUE(find(root, "a"));

    remove(root, "a");
    EXPECT_FALSE(find(root, "a"));
}

TEST(TrieTest, RemoveTest2) {
    TrieNode *root = new TrieNode();
    add(root, "a");
    add(root, "abcd");
    add(root, "ab");
    add(root, "abc");
    
    EXPECT_TRUE(find(root, "abcd"));
    EXPECT_TRUE(find(root, "abc"));
    EXPECT_TRUE(find(root, "ab"));
    EXPECT_TRUE(find(root, "a"));

    remove(root, "a");
    EXPECT_TRUE(find(root, "abcd"));
    EXPECT_TRUE(find(root, "abc"));
    EXPECT_TRUE(find(root, "ab"));
    EXPECT_TRUE(find(root, "a"));

    remove(root, "ab");
    EXPECT_TRUE(find(root, "abcd"));
    EXPECT_TRUE(find(root, "abc"));
    EXPECT_TRUE(find(root, "ab"));
    EXPECT_TRUE(find(root, "a"));

    remove(root, "abc");
    EXPECT_TRUE(find(root, "abcd"));
    EXPECT_TRUE(find(root, "abc"));
    EXPECT_TRUE(find(root, "ab"));
    EXPECT_TRUE(find(root, "a"));

    remove(root, "abcd");
    EXPECT_FALSE(find(root, "a"));
    EXPECT_FALSE(find(root, "ab"));
    EXPECT_FALSE(find(root, "abc"));
    EXPECT_FALSE(find(root, "abcd"));
}

TEST(TrieTest, RemoveTest3) {
    TrieNode *root = new TrieNode();
    add(root, "a");
    add(root, "abcd");
    add(root, "ab");
    add(root, "abc");
    
    EXPECT_TRUE(find(root, "abcd"));
    EXPECT_TRUE(find(root, "abc"));
    EXPECT_TRUE(find(root, "ab"));
    EXPECT_TRUE(find(root, "a"));

    remove(root, "a");
    EXPECT_TRUE(find(root, "abcd"));
    EXPECT_TRUE(find(root, "abc"));
    EXPECT_TRUE(find(root, "ab"));
    EXPECT_TRUE(find(root, "a"));

    remove(root, "a");
    EXPECT_TRUE(find(root, "abcd"));
    EXPECT_TRUE(find(root, "abc"));
    EXPECT_TRUE(find(root, "ab"));
    EXPECT_TRUE(find(root, "a"));

    remove(root, "a");
    EXPECT_TRUE(find(root, "abcd"));
    EXPECT_TRUE(find(root, "abc"));
    EXPECT_TRUE(find(root, "ab"));
    EXPECT_TRUE(find(root, "a"));

    remove(root, "a");
    EXPECT_FALSE(find(root, "a"));
    EXPECT_FALSE(find(root, "ab"));
    EXPECT_FALSE(find(root, "abc"));
    EXPECT_FALSE(find(root, "abcd"));
}