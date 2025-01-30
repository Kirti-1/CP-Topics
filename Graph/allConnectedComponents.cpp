
/*
All connected components
Problem statement
Given an undirected graph G(V,E), find and print all the connected components of the given graph G.

V is the number of vertices present in graph G and vertices are numbered from 1 to V.

E is the number of edges present in graph G.

You need to take input in main and create a function which should return all the connected components. And then print them in the main, not inside function.

Print different components in new line. And each component should be printed in increasing order (separated by space). Order of different components doesn't matter.

Detailed explanation ( Input/output format, Notes, Images )
Constraints :
2 <= V <= 10000
1 <= E <= 10000
Sample Input 1:
1
4 2
2 1
4 3
Sample Output 1:
1 2 
4 3 
*/
//used adjacency list instaed of adjacency matrix to avoid TLE for cases such as where N number of vertices are present and the space complexity goes to O(N^2)
#include <bits/stdc++.h>
using namespace std;

void getPathBFS(vector<vector<int>> &edges, int n, int sp, int *visited, vector<int> &path){
    visited[sp] =1;
    queue<int> que;
    path.push_back(sp);
    que.push(sp);
    while(!que.empty()){
        int ele = que.front();
        que.pop();
        for(int i:edges[ele]){
            if(visited[i] == 0){
                que.push(i);
                visited[i] = 1;
                path.push_back(i);
            }
        }
    } 
}

void getConnectedComponents(vector<vector<int>> &edges, int n, vector<vector<int>> &allComp ){
    int *visited = new int[n+1]{0};
    for(int i=1;i<=n;i++){
        if(visited[i] == 0){
            vector<int> path;
            getPathBFS(edges, n, i, visited, path);
            sort(path.begin(), path.end());
            allComp.push_back(path);
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, e;
        cin >> n >> e;
        vector<vector<int>> edges(n+1);
        /* 
        //trying with adjacency List approach instead as giving TLE for some cases
        int **edges = new int *[n+1];
        for (int i=0; i <=n; i++) {
            edges[i] = new int[n+1]{0};
        }*/
        for(int i=0;i<e;i++){
            int fv, sv;
            cin>>fv>>sv;
            edges[fv].push_back(sv);
            edges[sv].push_back(fv); 
        }

        vector<vector<int>> allComponents;
        
        getConnectedComponents(edges, n, allComponents);
        for(int i=0;i<allComponents.size();i++){
            for(int j=0;j<allComponents[i].size();j++){
                cout<<allComponents[i][j] << " ";
            }
            cout<<endl;
        }

    }
    return 0;
}