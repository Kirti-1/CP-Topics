/*
Largest Piece
Its Gary's birthday today and he has ordered his favourite square cake consisting of '0's and '1's . But Gary wants the biggest piece of '1's and no '0's . A piece of cake is defined as a part which consist of only '1's, and all '1's share an edge with eachother on the cake. Given the size of cake N and the cake , can you find the size of the biggest piece of '1's for Gary ?

Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 10
1 <= N <= 1000
Sample Input :
1
2
11
01
Sample Output :
3

*/
#include <bits/stdc++.h>
using namespace std;

// Directions for moving up, down, left, right
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool isValid(int x, int y, int n) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

// DFS function to explore connected '1's
int dfs(vector<vector<int>> &cake, vector<vector<bool>> &visited, int i, int j, int n) {
    visited[i][j] = true;
    int size = 1; // current cell is part of the connected component
    
    // Check in all 4 possible directions
    for (int k = 0; k < 4; k++) {
        int ni = i + dx[k];
        int nj = j + dy[k];
        
        if (isValid(ni, nj, n) && !visited[ni][nj] && cake[ni][nj] == 1) {
            size += dfs(cake, visited, ni, nj, n);
        }
    }
    
    return size;
}

int getBiggestPieceSize(vector<vector<int>> &cake, int n) {
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    int max_piece = 0;
    
    // Traverse all cells to find unvisited '1's
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (cake[i][j] == 1 && !visited[i][j]) {
                int piece_size = dfs(cake, visited, i, j, n);
                max_piece = max(max_piece, piece_size);
            }
        }
    }
    
    return max_piece;
}

int main() {
    int T; // Number of test cases
    cin >> T;
    
    while (T--) {
        int n; // Size of the cake (NxN)
        cin >> n;
        
        vector<vector<int>> cake(n, vector<int>(n));
        
        // Read the cake grid
        for (int i = 0; i < n; ++i) {
            string row;
            cin >> row;
            for (int j = 0; j < n; ++j) {
                cake[i][j] = row[j] - '0'; // Convert '1'/'0' to integer
            }
        }
        
        // Get the size of the biggest piece of '1's
        cout << getBiggestPieceSize(cake, n) << endl;
    }
    
    return 0;
}
