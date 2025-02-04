/*
3 Cycle
Given a graph with N vertices (numbered from 1 to N) and Two Lists (U,V) of size M where (U[i],V[i]) and (V[i],U[i]) are connected by an edge , then count the distinct 3-cycles in the graph. A 3-cycle PQR is a cycle in which (P,Q), (Q,R) and (R,P) are connected an edge.

Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1<=N<=100
1<=M<=(N*(N-1))/2
1<=u[i],v[i]<=N
Sample Input:
3 3
1 2 3
2 3 1
Sample Output:
1
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int solve(int n, int m, vector<int>& u, vector<int>& v) {
    // Create an adjacency list using unordered_map and unordered_set
    unordered_map<int, unordered_set<int>> adj;

    // Populate the adjacency list with edges
    for (int i = 0; i < m; i++) {
        adj[u[i]].insert(v[i]);
        adj[v[i]].insert(u[i]);
    }

    int thcycle = 0;

    // Iterate through all edges
    for (int i = 0; i < m; i++) {
        int u_node = u[i], v_node = v[i];

        // Find common neighbors between u_node and v_node
        // They form a 3-cycle with u_node and v_node
        for (int neighbor : adj[u_node]) {
            if (neighbor != v_node && adj[v_node].count(neighbor)) {
                thcycle++;
            }
        }
    }

    // Each 3-cycle is counted 3 times, once for each edge in the cycle
    return thcycle / 3;
}

int main() {
    int n, m;
    cin >> n >> m;  // Read the number of vertices and edges

    vector<int> u(m), v(m);

    // Read the edges from input
    for (int i = 0; i < m; i++) {
        cin >> u[i];  // Read each edge u[i] and v[i]
    }

    // Read the edges from input
    for (int i = 0; i < m; i++) {
        cin >>v[i];  // Read each edge u[i] and v[i]
    }

    // Call the function to count 3-cycles
    cout << solve(n, m, u, v) << endl;

    return 0;
}
