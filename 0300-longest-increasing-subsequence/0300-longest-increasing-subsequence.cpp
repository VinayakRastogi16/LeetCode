class Solution {
public:

    int tabulation(vector<int>& nums){
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        

        for(int i = n-1; i>=0; i--){
            for(int j = i-1; j>=-1; j--){
                int take = 0;

                if(j ==-1 ||nums[i]>nums[j])
                take = 1 + dp[i+1][i+1];

                int notTake = dp[i+1][j+1];

                dp[i][j+1] = max(take, notTake);
            }
        }

        return dp[0][0];
    }

    int solve(int i, int prevIdx, vector<int>& nums, vector<vector<int>>& dp){

        if(i == nums.size())
            return 0;

        if(dp[i][prevIdx+1] != -1)return dp[i][prevIdx+1];

        int take = 0;

        if(prevIdx == -1 || nums[i] > nums[prevIdx])
            take = 1+solve(i+1,i, nums, dp);

        int notTake = solve(i+1, prevIdx, nums, dp);

        return dp[i][prevIdx+1] = max(take, notTake);

    }

    int lengthOfLIS(vector<int>& nums) {

        vector<vector<int>> dp(nums.size(), vector<int>(nums.size()+1, -1));

        // return solve(0, -1, nums, dp);
        return tabulation(nums);
    }
};