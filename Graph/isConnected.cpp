/*
Is Connected
Problem statement
Given an undirected graph G(V,E), check if the graph G is connected graph or not.

V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.

E is the number of edges present in graph G.

Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= T <= 10
2 <= V <= 1000
1 <= E <= 1000
Sample Input 1:
1
4 4
0 1
0 3
1 2
2 3
Sample Output 1:
true
Sample Input 2:
1
4 3
0 1
1 3 
0 3
Sample Output 2:
false 
Sample Output 2 Explanation
The graph is not connected, even though vertices 0,1 and 3 are connected to each other but there isn’t any path from vertices 0,1,3 to vertex 2. 
*/
#include<map>
#include<bits/stdc++.h>
using namespace std;
void isConnected(int **edges, int n, int *visited, int sp){
    //Finding is the graph connected using BFS(Level order Traversal)
    queue<int> que;
    que.push(sp);
    visited[sp]  = 1;
    while(!que.empty()){
        int ele = que.front();
        que.pop();
        for(int i=0;i<n;i++) {
            if (edges[ele][i] == 1 && visited[i] == 0) {
                que.push(i);
                visited[i] = 1;
            }
        }
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
        int *visited = new int[n]{0};
        //any starting point would work so we are taking 0 as vertices are numbered from 0 to V-1.
        isConnected(edges, n, visited,0);
        int isConn = 1;
        for(int i=0;i<n;i++){
            if(visited[i] == 0){
                cout << "false";
                isConn = 0;
                 break;
            }
        }
        if(isConn==1) cout << "true" ;
        cout<<endl;
    }
    return 0;
}