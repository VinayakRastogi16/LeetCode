class Solution {
public:


    int tabulation(vector<int>& nums){
        int n = nums.size();
        vector<int> dp(n+2, 0);

        for(int i = n-1; i>=0; i--){
            dp[i] = max(nums[i]+dp[i+2], dp[i+1]);
        }

        return dp[0];

    }   

    int solve(vector<int>& nums, int i, vector<int>& dp){
        if(i>=nums.size())return 0;

        if(dp[i]!=-1)return dp[i];

        int ans = max(nums[i]+solve(nums, i+2, dp), solve(nums, i+1, dp));

        return dp[i] = ans;
    }

    int rob(vector<int>& nums) {

        vector<int> dp(nums.size(), -1);

        // return solve(nums, 0, dp);

        return tabulation(nums);
        
    }
};