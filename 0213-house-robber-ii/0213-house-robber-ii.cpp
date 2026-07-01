class Solution {
public:
    int tabulation(vector<int>& nums, int start, int end){
        int n = nums.size();
        vector<int> dp(n+2, 0);

        for(int i = end; i>=start; i--){
            dp[i] = max(nums[i]+dp[i+2], dp[i+1]);
        }

        return dp[start];
    }


    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];

        return max(tabulation(nums, 0, n-2), tabulation(nums, 1, n-1));
    }
};