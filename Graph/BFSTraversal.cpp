/*
BFS
Problem statement
Given an undirected graph G(V, E), print its BFS traversal.

Here you need to consider that you need to print BFS path starting from vertex 0 only.

V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.

E is the number of edges present in graph G.

Note :
1. Take graph input in the adjacency matrix.
2. Handle for Disconnected Graphs as well
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
2 <= V <= 1000

1 <= E <= 1000

Sample Input 1:
4 4
0 1
0 3
1 2
2 3
Sample Output 1:
0 1 3 2
*/
#include<bits/stdc++.h>
using namespace std;
void BreadthFirstTraversal(int **edges, int n, int si, int *visited) {
    
    queue<int> que;
    // given in question to start from vertex 0 only and also to handle disconnected graphs
    que.push(si);
    visited[si] = 1;
    //This portion only handles connected graph
    while(!que.empty()){
        int ele = que.front();
        cout << ele << " ";
        que.pop();
        for(int i=0;i<n;i++){
            if(ele == i) continue;
            if(edges[ele][i] == 1){
                if(visited[i] == 0){
                    que.push(i);
                    visited[i] = 1;
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        if(visited[i] == 0){
            BreadthFirstTraversal(edges, n, i, visited);
        }
    }
}
int main(){
    
    // write your code here
    int n,e;
    cin>>n>>e;

    //let's create an adjancency matrix for storing edges details
    int **edges = new int*[n];

    for(int i=0;i<n;i++){
        edges[i] = new int[n]{0};
    }

    for(int i=0;i<e;i++){
        int fv, sv;
        cin>>fv>>sv;
        edges[fv][sv] = 1;
        edges[sv][fv] = 1;
    }
    /*for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << edges[i][j] << " ";
        }
        cout << endl;
    }*/
    int *visited = new int[n]{0};
    BreadthFirstTraversal(edges, n, 0, visited);
    return 0;
}