# GRAPH 

A graph is a set of vertices and edges, with no pattern necessarily unlike tree. 

## Why we need graph? 

We are not able to put all the data into the tree as there might be a possiblility that there is no connection between two nodes/dataset {like linkedin; two people know each other might not know the 3rd person, a road network; non uniform structure} 

## Points to Note: 

Not necessarily there is a connection between two nodes. 

Tree is a special kind of graph where all nodes are connected and is acyclic (don’t have any cycles) 

## Graphs Terminologies: 

*   Nodes are named vertices, connection between them is called edges. 
*   Two vertices are said to be adjacent if there exists a direct edge between them. 
*   The degree of a node is defined as the number of edges that is going through it. 
*   A path is a collection of edges through which we can reach from one node to other in a graph. 
*   A graph is said to be connected if there is a path between every pair of vertices. 
*   If the graph is not connected, then all the connected subsets of the graphs are called connected components. Each connected components are connected within the self, but two different components of a graph are never connected. 
*   The minimum number of edges in a graph can be zero, which means a graph can have no edges as well. 
*   The minimum number of edges in a connected graph will be (N-1), where N is the number of nodes. 
*   In a complete graph (where each node is connected to every other node by a direct edge), there can be NC2 number of edges means N(N-1)/2 edges, where N is the number of nodes. This is the maximum number of edges that a graph can have. 
*   Hence, if an algorithm works on the terms of edges, let’s say 0(E), where E is the number of edges, then in the worst case, the algorithm will take O(N2). 
    

## Graph Representation 

Ways to implement graphs 

1.  Using edge list:  
    
A class can be created to store an array of edges. 
The array contains all pairs of connected nodes. 
Checking if two nodes are connected requires scanning the entire array. 
In the worst case, searching takes O(n²) time. 
The given graph can be visualized using an edge list format. 

2.  Adjacency List:  
    
An adjacency list uses an array of vertices. 
Each vertex has a list of edges connecting it to other vertices. 
To check for an edge, we look at one node’s list for the target node. 
This reduces the search time to O(n). 

3.  Adjacency Matrix:  An adjacency matrix uses a 2D array to represent edges. 
    

The cell (i, j) indicates an edge between node i and node j. 
It is easy to implement and is widely used. 
Major disadvantage: higher space consumption compared to the adjacency list.  
In the adjacency list, each node stores only directly connected nodes. 
The adjacency matrix for the given graph can be visualized in the matrix form.