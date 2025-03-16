#include<iostream>
using namespace std;


class MinSegmentTree{
    public:
        void buildMinSegmentTree(int *arr, int *segtree, int start, int end, int headNode){

            // base case
            if(start == end){
                // when only one element is left then that element will be the minimum
                segtree[headNode] = arr[start];
                return;
            }

            int mid = (start + end) / 2;
            //build left half min segment tree
            buildMinSegmentTree(arr, segtree, start, mid, 2 * headNode);
            //build right half min segment tree
            buildMinSegmentTree(arr, segtree, mid + 1, end, 2 * headNode +1);

            // find the min from left and right tree headnode and place the minimum into start to end range
            segtree[headNode] = min(segtree[2 * headNode], segtree[2 * headNode + 1]);
        }
};

int findMinimumInRange(int *segtree, int start, int end, int l, int r, int headNode){



    if(r < start || l > end){
        //out of range
        return INT_MAX;
    }
    if(l>=start && r<=end){
        //complete overlap
        return segtree[headNode];
    }

    if(start == end){
        return segtree[headNode];
    }
    int mid = (start + end)/2;
    int minl = findMinimumInRange(segtree, start, mid, l, r, 2*headNode);
    int minr = findMinimumInRange(segtree, mid+1, end, l, r, 2*headNode + 1);

    return min(minl, minr);



}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    int *segtree = new int[3 * n];
    MinSegmentTree obj;
    obj.buildMinSegmentTree(arr, segtree, 0, n-1, 1);
    // cout << segtree[1];

    // query within the specified range
    // t queries
    int t;
    cin >> t;
    while(t--){
        int x, y;
        cin >> x >> y;
        cout << findMinimumInRange(segtree, 0, n-1, x, y, 1) << endl;
    }
    

}