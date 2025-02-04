/*
Connecting Dots
Gary has a board of size NxM. Each cell in the board is a coloured dot. There exist only 26 colours denoted by uppercase Latin characters (i.e. A,B,...,Z). Now Gary is getting bore and wants to play a game. The key of this game is to find a cycle that contain dots of same colour. Formally, we call a sequence of dots d1, d2, ..., dk a cycle if and only if it meets the following condition:

1. These k dots are different: if i ≠ j then di is different from dj.
2. k is at least 4.
3. All dots belong to the same colour.
4. For all 1 ≤ i ≤ k - 1: di and di + 1 are adjacent. Also, dk and d1 should also be adjacent. Cells x and y are called adjacent if they share an edge.
Since Gary is colour blind, he wants your help. Your task is to determine if there exists a cycle on the board.

Assume input to be 0-indexed based.
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
2 ≤ N, M ≤ 400
Sample Input :
3 4
AAAA
ABCA
AAAA
Sample Output :
1
*/
#include <bits/stdc++.h>
using namespace std;

int N, M; // dimensions of the grid
vector<string> board; // the board grid

// Directions for moving to adjacent cells: up, down, left, right
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool isValid(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < M;
}

bool dfs(int x, int y, int px, int py, char color, vector<vector<bool>>& visited, vector<vector<bool>>& onPath, int count) {
    // Mark the current cell as visited and part of the current path
    visited[x][y] = true;
    onPath[x][y] = true;
    
    // Explore all 4 directions (up, down, left, right)
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if (isValid(nx, ny) && board[nx][ny] == color) {
            if (!visited[nx][ny]) {
                // If it's not visited, continue DFS with the current cell as the previous cell
                if (dfs(nx, ny, x, y, color, visited, onPath, count + 1)) {
                    return true;
                }
            } else if (onPath[nx][ny] && !(nx == px && ny == py) && count >= 3) {
                // Found a cycle of length >= 4 (not coming back to the immediate previous cell)
                return true;
            }
        }
    }
    
    // Backtrack, unmark the current cell as part of the path
    onPath[x][y] = false;
    return false;
}

bool findCycle() {
    vector<vector<bool>> visited(N, vector<bool>(M, false));  // Track if a cell has been visited
    vector<vector<bool>> onPath(N, vector<bool>(M, false));   // Track the cells in the current DFS path
    
    // Start DFS from every cell
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!visited[i][j]) {
                // Perform DFS if the cell hasn't been visited
                if (dfs(i, j, -1, -1, board[i][j], visited, onPath, 1)) {
                    return true;
                }
            }
        }
    }
    
    return false;
}

int main() {
    cin >> N >> M;
    board.resize(N);
    
    for (int i = 0; i < N; i++) {
        cin >> board[i];
    }
    
    if (findCycle()) {
        cout << 1 << endl;  // If a cycle exists
    } else {
        cout << 0 << endl;  // If no cycle exists
    }
    
    return 0;
}
