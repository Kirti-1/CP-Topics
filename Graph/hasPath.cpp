/*
Has Path
Problem statement
Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), check if there exists any path between them or not. Print true or false.

V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.

E is the number of edges present in graph G.

Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= T <= 10
2 <= V <= 1000
1 <= E <= 1000
0 <= v1, v2 <= V-1
Sample Input 1 :
1
4 4
0 1
0 3
1 2
2 3
1 3
Sample Output 1 :
true
Sample Input 2 :
1
6 3
5 3
0 1
3 4
0 3
Sample Output 2 :
false
*/
#include <bits/stdc++.h>
using namespace std;

bool hasPath(int **edges, int n, int v1, int v2, int *visited) {
    if (v1 == v2) return true; // Base case: if source is destination
    
    visited[v1] = 1; // Mark current node as visited
    
    for (int i = 0; i < n; i++) {
        if (edges[v1][i] == 1 && !visited[i]) { // Check unvisited neighbors
            if (hasPath(edges, n, i, v2, visited)) {
                return true; // If path found, return immediately
            }
        }
    }
    
    return false; // No path found
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, e;
        cin >> n >> e;

        // Initialize adjacency matrix
        int **edges = new int *[n];
        for (int i = 0; i < n; i++) {
            edges[i] = new int[n]{0};
        }

        // Read edges
        for (int i = 0; i < e; i++) {
            int fv, sv;
            cin >> fv >> sv;
            edges[fv][sv] = 1;
            edges[sv][fv] = 1;
        }

        int v1, v2;
        cin >> v1 >> v2;

        int *visited = new int[n]{0}; // Visited array
        cout << (hasPath(edges, n, v1, v2, visited) ? "true" : "false") << endl;

        // Free memory
        delete[] visited;
        for (int i = 0; i < n; i++) {
            delete[] edges[i];
        }
        delete[] edges;
    }
    return 0;
}
