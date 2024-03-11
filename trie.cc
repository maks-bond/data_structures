#include "trie.hh"

namespace {

}

TrieNode::TrieNode() {
    children = std::vector<TrieNode *>('z'-'a' + 1, nullptr);
}

void add(TrieNode *root, const std::string &s) {
    TrieNode *node = root;
    for(const char c : s) {
        node->count++;
        int idx = c-'a';
        if(!node->children[idx]) node->children[idx] = new TrieNode();
        node = node->children[idx];
    }
    node->count++;
}

void remove(TrieNode *root, const std::string &s) {
    TrieNode *node = root;
    for(const char c : s) {
        int idx = c-'a';
        if(!node->children[idx]) {
            return;
        }
        
        auto *child_node = node->children[idx];
        if(!child_node) return;

        child_node->count--;
        if(child_node->count <= 0) {
            // Ideally we should also iterate over children of child node and delete all of them to clear the memory.
            delete child_node;
            node->children[idx] = nullptr;
            return;
        }

        node = node->children[idx];
    }
}

bool find(TrieNode *root, const std::string &s) {
    TrieNode *node = root;
    for(const char c : s) {
        int idx = c-'a';
        if(!node->children[idx]) return false;
        node = node->children[idx];
    }

    return true;
}

Trie::Trie() : root(new TrieNode()) {}
Trie::~Trie() {
    delete root;
}


void Trie::add(const std::string &s) {
    ::add(root, s);
}

void Trie::remove(const std::string &s) {
    ::remove(root, s);
}

bool Trie::find(const std::string &s) const {
    return ::find(root, s);
}
