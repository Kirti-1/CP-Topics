#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    TrieNode* left = nullptr;  // Represents bit 0
    TrieNode* right = nullptr; // Represents bit 1
};

void insert(TrieNode* head, int n) {
    TrieNode* curr = head;
    for (int i = 31; i >= 0; i--) {
        int b = (n >> i) & 1;
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

int maximumXORSubarray(TrieNode* root, int size, vector<int>& arr) {
    int max_xor = INT_MIN;
    for (int i = 0; i < size; i++) {
        TrieNode* curr = root;
        int ele = arr[i];
        int curr_xor = 0;
        for (int j = 31; j >= 0; j--) {
            int b = (ele >> j) & 1;

            if (b == 0) {
                if (curr->right) {
                    curr_xor += (1 << j); // Using bitwise shift instead of pow
                    curr = curr->right;
                } else {
                    curr = curr->left;
                }
            } else {
                if (curr->left) {
                    curr_xor += (1 << j); // Using bitwise shift instead of pow
                    curr = curr->left;
                } else {
                    curr = curr->right;
                }
            }
        }
        if (max_xor < curr_xor) {
            max_xor = curr_xor;
        }
    }
    return max_xor;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    TrieNode* root = new TrieNode();

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        insert(root, arr[i]);
    }

    cout << maximumXORSubarray(root, n, arr) << endl;

    return 0;
}
