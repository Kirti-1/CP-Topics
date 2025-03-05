#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    TrieNode* left = nullptr;  // Represents bit 0
    TrieNode* right = nullptr; // Represents bit 1
};

void insert(TrieNode* head, int prefixXor) {
    TrieNode* curr = head;
    for (int i = 31; i >= 0; i--) {
        int b = (prefixXor >> i) & 1;
        if (b == 0) {
            if (!curr->left) {
                curr->left = new TrieNode();
            }
            curr = curr->left;
        } else {
            if (!curr->right) {
                curr->right = new TrieNode();
            }
            curr = curr->right;
        }
    }
}

int query(TrieNode* root, int prefixXor) {
    TrieNode* curr = root;
    int max_xor = 0;

    for (int i = 31; i >= 0; i--) {
        int b = (prefixXor >> i) & 1;
        if (b == 0) {
            if (curr->right) { // Try to go opposite to maximize XOR
                max_xor |= (1 << i);
                curr = curr->right;
            } else {
                curr = curr->left;
            }
        } else {
            if (curr->left) { // Try to go opposite to maximize XOR
                max_xor |= (1 << i);
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }
    }
    return max_xor;
}

int maximumXORSubarray(vector<int>& arr) {
    TrieNode* root = new TrieNode();
    
    insert(root, 0); // Insert 0 to handle case where prefixXor itself is max

    int prefixXor = 0, max_xor = 0;

    for (int num : arr) {
        prefixXor ^= num; // Compute prefix XOR
        max_xor = max(max_xor, query(root, prefixXor)); // Find max XOR with existing prefixes
        insert(root, prefixXor); // Insert current prefix XOR into the Trie
    }

    return max_xor;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << maximumXORSubarray(arr) << endl;

    return 0;
}
