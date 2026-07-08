class Solution {
public:

    int memoization(int i, int target, vector<int>& nums, vector<vector<int>>& dp){

        // if(target == 0) return 1;

        if(i == nums.size()) return (target == 0);

        if(dp[i][target] != -1) return dp[i][target];

        int take = 0;

        if(nums[i] <= target)
            take = memoization(i+1, target-nums[i], nums, dp);

        int notTake = memoization(i+1, target, nums, dp);

        return dp[i][target] = take+notTake;

    }

    int solve(int i, int sum, int target, vector<int>& nums){
        if(i == nums.size()) return (sum == target);

        int plus = solve(i+1, sum+nums[i], target, nums);
        int minus = solve(i+1, sum-nums[i], target, nums);

        return plus+minus;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = target;
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        if(abs(target) > totalSum || (target+totalSum)%2 != 0 ) return 0;

        int reqSum = (target+totalSum)/2;

        vector<vector<int>> dp(nums.size()+1, vector<int>(reqSum+1, -1));

        return memoization(0, reqSum, nums, dp);

        // return solve(0, 0, target, nums);
    }
};