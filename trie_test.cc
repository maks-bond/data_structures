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
    Trie trie;
    trie.add("abcd");
    EXPECT_TRUE(trie.find("abcd"));
    EXPECT_TRUE(trie.find("abc"));
    EXPECT_TRUE(trie.find("ab"));
    EXPECT_TRUE(trie.find("a"));
    EXPECT_FALSE(trie.find("bcd"));
}

TEST(TrieTest, RemoveTest) {
    Trie trie;
    trie.add("abcd");
    trie.add("abc");
    trie.add("ab");
    trie.add("a");
    EXPECT_TRUE(trie.find("abcd"));

    trie.remove("abcd");
    EXPECT_FALSE(trie.find("abcd"));
    EXPECT_TRUE(trie.find("abc"));

    trie.remove("abc");
    EXPECT_FALSE(trie.find("abc"));
    EXPECT_TRUE(trie.find("ab"));

    trie.remove("ab");
    EXPECT_FALSE(trie.find("ab"));
    EXPECT_TRUE(trie.find("a"));

    trie.remove("a");
    EXPECT_FALSE(trie.find("a"));
}

TEST(TrieTest, RemoveTest2) {
    Trie trie;
    trie.add("a");
    trie.add("abcd");
    trie.add("ab");
    trie.add("abc");
    
    EXPECT_TRUE(trie.find("abcd"));
    EXPECT_TRUE(trie.find("abc"));
    EXPECT_TRUE(trie.find("ab"));
    EXPECT_TRUE(trie.find("a"));

    trie.remove("a");
    EXPECT_TRUE(trie.find("abcd"));
    EXPECT_TRUE(trie.find("abc"));
    EXPECT_TRUE(trie.find("ab"));
    EXPECT_TRUE(trie.find("a"));

    trie.remove("ab");
    EXPECT_TRUE(trie.find("abcd"));
    EXPECT_TRUE(trie.find("abc"));
    EXPECT_TRUE(trie.find("ab"));
    EXPECT_TRUE(trie.find("a"));

    trie.remove("abc");
    EXPECT_TRUE(trie.find("abcd"));
    EXPECT_TRUE(trie.find("abc"));
    EXPECT_TRUE(trie.find("ab"));
    EXPECT_TRUE(trie.find("a"));

    trie.remove("abcd");
    EXPECT_FALSE(trie.find("a"));
    EXPECT_FALSE(trie.find("ab"));
    EXPECT_FALSE(trie.find("abc"));
    EXPECT_FALSE(trie.find("abcd"));
}

TEST(TrieTest, RemoveTest3) {
    Trie trie;
    trie.add("a");
    trie.add("abcd");
    trie.add("ab");
    trie.add("abc");
    
    EXPECT_TRUE(trie.find("abcd"));
    EXPECT_TRUE(trie.find("abc"));
    EXPECT_TRUE(trie.find("ab"));
    EXPECT_TRUE(trie.find("a"));

    trie.remove("a");
    EXPECT_TRUE(trie.find("abcd"));
    EXPECT_TRUE(trie.find("abc"));
    EXPECT_TRUE(trie.find("ab"));
    EXPECT_TRUE(trie.find("a"));

    trie.remove("a");
    EXPECT_TRUE(trie.find("abcd"));
    EXPECT_TRUE(trie.find("abc"));
    EXPECT_TRUE(trie.find("ab"));
    EXPECT_TRUE(trie.find("a"));

    trie.remove("a");
    EXPECT_TRUE(trie.find("abcd"));
    EXPECT_TRUE(trie.find("abc"));
    EXPECT_TRUE(trie.find("ab"));
    EXPECT_TRUE(trie.find("a"));

    trie.remove("a");
    EXPECT_FALSE(trie.find("abcd"));
    EXPECT_FALSE(trie.find("abc"));
    EXPECT_FALSE(trie.find("ab"));
    EXPECT_FALSE(trie.find("a"));
}