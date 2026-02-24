#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> ans;
    int n = nums.size();
    sort(nums.begin(), nums.end());
    if (n<3)
    {
        return ans;
    }
    
    for (int i = 0; i < n-2; i++)
    {
        if (i>0 && nums[i] == nums[i-1])
        {
            continue;
        }
        int j = i+1;
        int k = n-1;
        
        
        while(j<k){
            if (nums[j]+nums[k]== -nums[i])
            {
                ans.push_back({nums[i], nums[j], nums[k]});
                j++;
                k--;

                while (j<k && nums[j] == nums[j+1])
                {
                    j++;
                }
                while(j<k && nums[k] == nums[k-1]){
                    k--;
                }
                

            }else if (nums[j]+nums[k]<-nums[i])
            {
                j++;
            }else{
                k--;
            }
            
            
        }
        
    }
    
    return ans;
    
    
}


int main(){
    vector<int> nums = {-1,0,1,2,-1,-4};
    auto res = threeSum(nums);
    for (auto &v : res) {
        cout << v[0] << " " << v[1] << " " << v[2] << endl;
    }
    return 0;
}