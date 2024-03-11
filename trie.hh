#pragma once

#include <vector>
#include <string>

struct TrieNode {
    TrieNode();

    std::vector<TrieNode *> children;
    int count = 0;
};

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