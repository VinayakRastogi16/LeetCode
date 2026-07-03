class Solution {
public:

    bool tabulation(vector<int>& nums, int target){

        int n = nums.size();

        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));

        for (int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }

        for (int i = n - 1; i >= 0; i--) {

            for (int t = 1; t <= target; t++) {

                bool take = false;

                if (nums[i] <= t)
                    take = dp[i + 1][t - nums[i]];

                bool notTake = dp[i + 1][t];

                dp[i][t] = take || notTake;
            }
        }

        return dp[0][target];
    }

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

        // return solve(nums, 0, sum/2, dp);

        return tabulation(nums, sum / 2);
    }
};