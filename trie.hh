#pragma once

#include <vector>

struct TrieNode {
    TrieNode();
    
    std::vector<TrieNode *> children;
};

class Trie {
};