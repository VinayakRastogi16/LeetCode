class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> ans;
    int n = nums.size(); 
    if (n<3) return ans;

    sort(nums.begin(), nums.end());
    
    for (int i = 0; i < n-2; i++)
    {
        if (i>0 && nums[i] == nums[i-1]) continue;

        int j = i+1;
        int k = n-1;
        
        
        while(j<k){
            if (nums[j]+nums[k]== -nums[i])
            {
                ans.push_back({nums[i], nums[j], nums[k]});
                j++;
                k--;

                while (j<k && nums[j] == nums[j-1])
                {
                    j++;
                }
                while(j<k && nums[k] == nums[k+1]){
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
};