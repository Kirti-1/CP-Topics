/*
Rectangular Area
Problem statement
You are given N rectangles, which are centered in the center of the Cartesian coordinate system and their sides are parallel to the coordinate axes. Each rectangle is uniquely identified with its width (along the x-axis) and height (along the y-axis). Navdeep has coloured each rectangle in a certain colour and now wants to know the area of the coloured part of the paper. Please refer to the sample test case 1 and image used in it for better understanding.

Sample Input 1 :
3 
8 2 (represented by white coloured rectangle)
4 4 (represented by blue coloured rectangle)
2 6 (represented by yellow coloured rectangle)
Sample Output 1 :
28
Alt Text

In other words, he wants to know the number of unit squares that belong to at least one rectangle. This can also be seen in the image. There are 28 unit squares, which come in the bounds of at least one rectangle.

Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= N <= 10^5
1 <= X,Y <= 10^5
All values of X and Y are even
Time Limit: 1 second 
Sample Input 1 :
3 
8 2
4 4 
2 6 
Sample Output 1 :
28
Sample Input 2 :
5 
2 10 
4 4 
2 2 
8 8 
6 6 
Sample Output 2 :
68

*/

#include<bits/stdc++.h>
using namespace std;
int main(){
    
    // write your code here

    int t;
    cin>>t;
    long area = 0;
    int max_x = 0;
    int* height = new int[50000000 + 2]();
    while(t--){
        int x,y;
        cin>>x>>y;
        if(height[x/2] < y){
            height[x/2] = y;
        }
        if(x/2 > max_x){
            max_x = x/2;
        }
    }
    for(int i=max_x;i>0;i--){
        if(height[i] < height[i+1]){
            height[i] = height[i+1];
        }
        area += height[i];
    }
    cout << area*2;
}