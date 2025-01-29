/* 
Get Path DFS
Problem statement
Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.

Find the path using DFS and print the first path that you encountered.

V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.

E is the number of edges present in graph G.

Print the path in reverse order. That is, print v2 first, then intermediate vertices and v1 at last.

Note : Save the input graph in Adjacency Matrix.
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
3 0 1
Sample Input 2 :
1
6 3
5 3
0 1
3 4
0 3
Sample Output 2 :
*/
#include <bits/stdc++.h>
using namespace std;

bool getPath(int **edges, int n, int v1, int v2, int *visited, vector<int> &path) {
    if (v1 == v2) { // If we reached the destination
        path.push_back(v2);
        return true;
    }

    visited[v1] = 1;  // Mark node as visited
    path.push_back(v1);

    for (int i = 0; i < n; i++) {
        if (edges[v1][i] == 1 && !visited[i]) {
            if (getPath(edges, n, i, v2, visited, path)) {
                return true; // If path found, return immediately
            }
        }
    }

    path.pop_back(); // Backtrack if no path found
    return false;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, e;
        cin >> n >> e;
        
        int **edges = new int *[n];
        for (int i = 0; i < n; i++) {
            edges[i] = new int[n]{0};
        }

        for (int i = 0; i < e; i++) {
            int fv, sv;
            cin >> fv >> sv;
            edges[fv][sv] = 1;
            edges[sv][fv] = 1;
        }

        int v1, v2;
        cin >> v1 >> v2;

        int *visited = new int[n]{0};
        vector<int> path;

        if (getPath(edges, n, v1, v2, visited, path)) {
            reverse(path.begin(), path.end());
            for (int node : path) {
                cout << node << " ";
            }
            cout << endl;
        }

        delete[] visited;
        for (int i = 0; i < n; i++) {
            delete[] edges[i];
        }
        delete[] edges;
    }
    return 0;
}
