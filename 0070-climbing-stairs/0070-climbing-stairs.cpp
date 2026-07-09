class Solution {
public:

    int tabulation(int n) {

        vector<int> dp(n+1, -1);

        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i-1]+dp[i-2];
        }

        return dp[n];
    }

    int memoization(int n, vector<int>& dp){
        if(n == 0 || n == 1) return 1;

        if(dp[n]!=-1){
            return dp[n];
        }

        int ans = memoization(n-1, dp)+memoization(n-2, dp);

        return dp[n] = ans;
    }


    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        
        return tabulation(n);
    }
};