class Solution {
public:

    int solve(int i, int j, vector<int>& nums, vector<vector<int>>& dp){
        if(i>j)return 0;

        if(dp[i][j]!=-1)return dp[i][j];

        int ans = 0;

        for(int k = i; k<=j; k++){
            int left = solve(i, k-1, nums, dp);
            int right = solve(k+1, j, nums, dp);

            ans = max(ans, left + nums[i-1]*nums[k]*nums[j+1] + right);
        }

        return dp[i][j] = ans;
    }


    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(1, n-2, nums, dp);
    }
};