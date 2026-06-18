class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int currSum = 0;
        vector<int> ans;
        for(int i = 0; i<nums.size(); i++){
            currSum += nums[i];

            ans.push_back(currSum);
        }

        return ans;
    }
};