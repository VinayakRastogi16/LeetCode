#include <iostream>
#include <vector>

using namespace std;

int MAXAREA(vector<int>& height){
    int n = height.size();
    int i = 0, j = n-1;
    int maxArea = 0;
    while (i<j)
    {  
        int area = min(height[i], height[j])*(j-i);
        maxArea = max(area, maxArea);
        if (height[i]<height[j])
        {
            i++;
        }else{
            j--;
        }
        
    }
    
    return maxArea;
    
    
}

int main(){
    vector<int> height = {1,8,6,2,5,4,8,3,7};

    cout<<MAXAREA(height)<<endl;
    return 0;
}