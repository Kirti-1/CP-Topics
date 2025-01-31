/*
Detect Cycle in a directed Graph
Problem statement
Given a directed graph, check whether the graph contains a cycle or not. Your function should return true if the given graph contains at least one cycle, else return false.

Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 10
1 <= V <= 10^3
0 <= E <= 10^3
0 <= A, B < V

Time Limit: 1 sec
Sample Input 1:.
2
4 4
0 1
1 2
2 3
3 0
3 3
1 0
1 2
0 2
Sample Output 1:
true
false
Explanation for Sample Input 1:
In the first case,
From node 0 we can reach 0 again by following this sequence of nodes in the path: 0,1,2,3,0. As we can see in the image below.
Example

In the second case,
There is no cycle in the given graph. As we can see in the image below.
Example

Sample Input 2:
2
3 2
0 1
0 2
3 3
1 1
0 2
1 2
Sample Output 2:
false
true

*/
#include <iostream>
#include <vector>
using namespace std;

bool isCyclicDFS(int v, vector<vector<int>> &adj, vector<int> &visited) {
    visited[v] = 1; // Mark as "in process"

    for (int neighbor : adj[v]) {
        if (visited[neighbor] == 0) { // If not visited, do DFS
            if (isCyclicDFS(neighbor, adj, visited))
                return true;
        } 
        else if (visited[neighbor] == 1) { // Back edge detected ? Cycle found
            return true;
        }
    }

    visited[v] = 2; // Mark as "processed"
    return false;
}

bool isCyclic(vector<vector<int>> &edges, int v, int e) {
    vector<vector<int>> adj(v); // Adjacency list representation

    // Build adjacency list from edge list
    for (auto edge : edges) {
        adj[edge[0]].push_back(edge[1]);
    }

    vector<int> visited(v, 0); // 0 = unvisited, 1 = in recursion stack, 2 = processed

    for (int i = 0; i < v; i++) { // Check all disconnected components
        if (visited[i] == 0) {
            if (isCyclicDFS(i, adj, visited))
                return true;
        }
    }

    return false;
}
