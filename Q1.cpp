#include <iostream>
#include <vector>
using namespace std;

int repeatedAndMissingNum(vector<int>& nums){
    int n = nums.size();

    vector<int> freq(n+1, 0);
    vector<int> error;

    for(int x : nums){
        freq[x]++;
    }

    for (int i = 0; i < n+1; i++)
    {
        if ((freq[i] == 2 && freq[i-1]==0))
        {
            if (i-1 == 0)
            {
                error.push_back(i);
                error.push_back(i+1);
            }else{
                error.push_back(i);
                error.push_back(i-1);
            }
            
        }else if(freq[i] == 2 && freq[i+1]==0){
            error.push_back(i);
            error.push_back(i+1);
        }
        
    }

    for (int i = 0; i < n; i++)
    {
        cout<<error[i]<<" ";
    }
    cout<<endl;
    return 0;
     
}


int main(){
    vector<int> nums = {1,1,3,4,4,6,7,8,9,9};
    repeatedAndMissingNum(nums);

    return 0;
}