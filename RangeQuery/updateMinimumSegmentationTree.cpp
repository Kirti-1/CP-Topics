#include <iostream>
#include "BuildSegmentTree.cpp"
using namespace std;

void updateBuildTree(int *arr, int* tree, int start, int end, int pos, int val, int headNode){
    if(pos < start && pos > end){
        // out of range
        return;
    }
    if(start == end){
        // we have reached the pos whose value needs to be updated
        arr[start]  = val;
        tree[headNode] = val;
        return;
    }
    int mid = (start + end)/2;
    if(pos <= mid){
        //traverse the left half and update the tree no need to go to right half
        updateBuildTree(arr, tree, start, mid, pos, val, 2 * headNode);
    }else{
        //traverse the right half and update the value
        updateBuildTree(arr, tree, mid+1, end, pos, val, 2 * headNode + 1);
    }
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
    SegmentTree tobj;
    //this tree is the sum of element within specified range tree and not the minimum tree but we can build that tree also by importing the class
    tobj.buildTree(arr, tree, 0, n-1, 1);


    //update the build tree at the position inputed
    int t;
    cin >> t;  
    //test cases
    while(t--){
        int pos, val;
        cin >> pos >> val;
        updateBuildTree(arr, tree, 0, n-1, pos, val, 1);
    }
    //print the tree after upadting all the values at specified position
    for(int i=1;i<3*n;i++){
        cout << tree[i] << "\n";
    }

}