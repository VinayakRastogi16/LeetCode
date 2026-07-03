class Solution {
public:

    bool solve(vector<int>& nums, int i, int target, vector<vector<int>>& dp){

        if(target == 0)return true;

        if(i == nums.size()) return false;

        if(dp[i][target] != -1){
            return dp[i][target];
        }

        bool take = false;

        if(nums[i] <= target)
         take = solve(nums, i+1, target - nums[i], dp);

        bool notTake = solve(nums, i+1, target,dp);

        return dp[i][target] =  take || notTake;

    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;

        for(int x : nums){
            sum += x;
        }


        if(sum%2 != 0){
            return false;
        }

        vector<vector<int>> dp(nums.size()+1, vector<int>(sum/2+1, -1));

        return solve(nums, 0, sum/2, dp);
    }
};