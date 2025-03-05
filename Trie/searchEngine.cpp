#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    TrieNode *children[26];
    bool leaf;
    int weight;

    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        leaf = false;
        weight = 0;
    }
};

void insertNode(TrieNode *head, string key, int weight) {
    TrieNode *curr = head;
    for (char c : key) {
        if (!curr->children[c - 'a']) {
            curr->children[c - 'a'] = new TrieNode(); // Fix: Assign the node properly
        }
        curr = curr->children[c - 'a'];
        
        // Store the maximum weight for this node
        if (curr->weight < weight) {
            curr->weight = weight;
        }
    }
    curr->leaf = true;
}

int traverseTrie(TrieNode *head, string text) {
    TrieNode *curr = head;
    for (char c : text) {
        if (!curr->children[c - 'a']) {
            return -1;  // Not found
        }
        curr = curr->children[c - 'a'];
    }
    return curr->weight; // Return the maximum weight found
}

vector<int> searchEngine(vector<pair<string, int>> database, vector<string> text) {
    TrieNode *head = new TrieNode();
    
    // Insert all words from the database
    for (const auto &pair : database) {
        insertNode(head, pair.first, pair.second);
    }

    // Search for each word in the query list
    vector<int> result;
    for (const string &query : text) {
        result.push_back(traverseTrie(head, query));
    }

    return result;
}
