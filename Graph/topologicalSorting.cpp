/*
Topological Sorting
Problem statement
Given a DAG(direct acyclic graph), return the Topological Sorting of a given graph.

Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 10
1 <= V <= 1000
0 <= E <= 3000
0 <= U, V <= V-1

Time Limit: 1sec
Sample Input 1:
1
5 4
0 2
1 2
3 1
0 4
Sample Output 1:
Correct
Sample Output 1 Explanation:
One correct sort order is : 3 1 0 4 2.

*/

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

// DFS approach to perform topological sort
void topoDFS(int node, stack<int> &topo, vector<int> &vis, vector<int> adj[]) {
    vis[node] = 1; // mark the node as visited

    for (auto i : adj[node]) {
        if (!vis[i]) topoDFS(i, topo, vis, adj); // Visit all the unvisited neighbors
    }

    topo.push(node); // After exploring all neighbors, push node to stack
}

// DFS-based topological sort
void topoSortDFS(int v, vector<int> adj[]) {
    stack<int> topo;
    vector<int> vis(v, 0);  // use v for size (0-indexed)

    // Perform DFS from all nodes (in case of disconnected components)
    for (int i = 0; i < v; i++) {
        if (!vis[i]) topoDFS(i, topo, vis, adj);
    }

    // Print the topological order
    while (!topo.empty()) {
        cout << topo.top() << " ";
        topo.pop();
    }
    cout << endl;
}

// Kahn's Algorithm (BFS approach)
vector<int> topoSortBFS(int v, vector<int> adj[]) {
    queue<int> nodes;
    vector<int> inDeg(v, 0);  // in-degree array (0-indexed)
    vector<int> ans;

    // Calculate in-degree of each node
    for (int i = 0; i < v; i++) {
        for (int j : adj[i]) {
            inDeg[j]++;
        }
    }

    // Add all nodes with in-degree 0 to the queue
    for (int i = 0; i < v; i++) {
        if (inDeg[i] == 0) {
            nodes.push(i);
        }
    }

    // Process nodes
    while (!nodes.empty()) {
        int n = nodes.front();
        ans.push_back(n);
        nodes.pop();

        // Reduce in-degree of all adjacent nodes
        for (int i : adj[n]) {
            inDeg[i]--;
            if (inDeg[i] == 0) {
                nodes.push(i);  // If in-degree becomes 0, add to queue
            }
        }
    }

    return ans;
}

// Main function to return topological sort based on the graph input
vector<int> topologicalSort(vector<vector<int>> &graph, int edges, int nodes) {
    vector<int> adjList[nodes];  // Create adjacency list array (0-indexed)

    // Input edges and fill adjacency list
    for (int i = 0; i < edges; i++) {
        int u = graph[i][0];  // Source node
        int v = graph[i][1];  // Destination node
        adjList[u].push_back(v);  // Add v to the adjacency list of u
    }

    // Choose the desired topological sort approach (DFS or BFS)
    return topoSortBFS(nodes, adjList);
}
