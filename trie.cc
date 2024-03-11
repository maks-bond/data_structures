#include "trie.hh"

TrieNode::TrieNode() {
    children = std::vector<TrieNode *>('z'-'a' + 1, nullptr);
}