#pragma once

#include <vector>
#include <string>

struct TrieNode {
    TrieNode();

    TrieNode * children[26] = {nullptr};
    int count = 0;
};

class Trie {
public:
    Trie();
    ~Trie();

    void add(const std::string &s);
    void remove(const std::string &s);
    bool find(const std::string &s) const;

private:
    TrieNode *root;
};

void add(TrieNode *root, const std::string &s);

void remove(TrieNode *root, const std::string &s);

bool find(TrieNode *root, const std::string &s);