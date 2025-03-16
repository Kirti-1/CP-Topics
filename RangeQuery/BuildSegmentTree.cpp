#include <iostream>
using namespace std;


//Lets convert the below into a class so that will be able to use into another file after importing
class SegmentTree{
    public:
        void buildTree(int *arr, int *tree,int start, int end, int headNode){
        // base case
        if(start == end){
            tree[headNode] = arr[start];
            return;
        }

        int mid = (start + end)/2;
        buildTree(arr, tree, start, mid, 2 * headNode);
        buildTree(arr, tree, mid+1, end, 2 * headNode + 1);
        tree[headNode] = tree[2 * headNode] + tree[2 * headNode + 1];
    }


};


/*
This is segment tree for sum of numbers within specified range thus when queried to provide 
the sum between a to b we can provide the sum in O(logn) time
*/
/*void buildTree(int *arr, int *tree,int start, int end, int headNode){
    // base case
    if(start == end){
        tree[headNode] = arr[start];
        return;
    }

    int mid = (start + end)/2;
    buildTree(arr, tree, start, mid, 2 * headNode);
    buildTree(arr, tree, mid+1, end, 2 * headNode + 1);
    tree[headNode] = tree[2 * headNode] + tree[2 * headNode + 1];
}
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    int *tree = new int[3 * n];
    SegmentTree s;
    s.buildTree(arr, tree, 0, n-1, 1);
    for(int i=1;i<3*n;i++){
        cout << tree[i] << "\n";
    }
    delete []tree;


}

*/