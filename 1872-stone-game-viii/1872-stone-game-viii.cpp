class Solution {
public:
    int n;

    int tabulation(vector<int>& prefix){
        vector<int> dp(n, 0);
        dp[n-1] = prefix[n-1];
        for(int i = n-2; i>=1; i--){
            int take = prefix[i] - dp[i+1];
            int skip = dp[i+1];

            dp[i] = max(take, skip);
        }
        return dp[1];
    }

    int solve(int i, vector<int>& prefix, vector<int>& dp){
        if(i==n-1)return prefix[n-1];
        if(dp[i]!=-1)return dp[i];

        int take = prefix[i] - solve(i+1, prefix, dp);
        int skip = solve(i+1, prefix, dp);

        return dp[i] = max(take, skip);
    }

    int stoneGameVIII(vector<int>& stones) {
        n = stones.size();
        vector<int> dp(n, -1);
        vector<int> prefix(n, 0);
        prefix[0] = stones[0];

        for(int i = 1; i<n; i++){
            prefix[i] = prefix[i-1]+stones[i];
        }

        // return solve(1, prefix, dp);
        return tabulation(prefix);
    }
};