/*
BFS
Problem statement
Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.

Find the path using BFS and print the shortest path available.

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
#include<map>
#include<bits/stdc++.h>
using namespace std;
void getPathBFS(int **edges, int n, int v1, int v2, int *visited , vector<int> &path){
    queue<int> que;

    //With the help of the map I'll backtrack my nodes for shortest path
    map<int, int> map;
    que.push(v1);
    visited[v1]  = 1;
    bool found = false;
    while(!que.empty() && !found){
        int ele = que.front();
        que.pop();
        for(int i=0;i<n;i++) {
            if (edges[ele][i] == 1 && visited[i] == 0) {
                map[i] = ele;
                que.push(i);
                visited[i] = 1;
                
                if (i == v2) {
                    found = true; // Stop BFS if v2 is found
                    break;
                }
            }
        }
    }
   
    // If path exists, reconstruct it
    if (map.find(v2) != map.end()) {
        int k = v2;
        path.push_back(k); // Include v2 in the path
        while (k != v1) {
            path.push_back(map[k]);
            k = map[k];
        }
        //reverse(path.begin(), path.end()); // Reverse to get correct order
    }
}
int main(){
    
    // write your code here
    int t;
    cin >> t;
    while(t--){
        int n, e;
        cin>>n>>e;
        int ** edges = new int*[n];
        for(int i=0;i<n;i++){
            edges[i] = new int[n]{0};
        }   
        for(int i=0;i<e;i++){
            int fv, sv;
            cin >> fv >> sv;
            edges[fv][sv] = 1;
            edges[sv][fv] = 1;
        }
        int v1,v2;
        cin >> v1 >> v2;
        int *visited = new int[n]{0};
        vector<int> path;
        getPathBFS(edges, n, v1, v2, visited, path);
        for(int i=0;i<path.size();i++){
            cout << path[i] << " ";
        }
        cout<<endl;
    }
    return 0;
}