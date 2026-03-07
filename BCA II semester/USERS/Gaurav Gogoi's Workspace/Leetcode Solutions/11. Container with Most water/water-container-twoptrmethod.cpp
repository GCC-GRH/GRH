#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector <int> height = {1,8,6,2,5,4,8,3,7};
    int ht, width, maxarea=0;
    int i=0,j=height.size()-1;
    while (i<j)
    {
        ht = min(height[i],height[j]);
        width = j-i;
        maxarea = max(maxarea, (ht*width));
        (height[i] < height[j]) ? i++ : j--;
    }
    cout<<maxarea;
    
}

// Linear time-complexity : O(n)