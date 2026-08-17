class Solution {
public:

    int solve(int l, int r, vector<int>& val, vector<vector<int>>& dp, vector<int>& prefix){ //Memoization
        if(l==r) return 0;

        if(dp[l][r]!=-1) return dp[l][r];

        int ans = 0;

        for(int k = l; k<r; k++){
            int lSum = prefix[k+1] - prefix[l];

            int rSum=prefix[r+1] - prefix[k+1];

            if(lSum<rSum){
                ans = max(ans, lSum+solve(l, k, val, dp, prefix));
            }else if(rSum<lSum){
                ans = max(ans, rSum+solve(k+1, r, val, dp, prefix));
            }else{
                ans = max(ans, lSum+max(solve(l, k, val, dp, prefix), solve(k+1,r, val, dp,prefix)));
            }
        }
        return dp[l][r] = ans;
    }

    // int stoneGameV(vector<int>& stoneValue) {
    //     int n = stoneValue.size();
    //     vector<vector<int>> dp(n, vector<int>(n, -1));

    //     vector<int> prefix(n+1, 0);
    //     for(int i = 0; i < n; i++){
    //         prefix[i+1] = prefix[i]+stoneValue[i];
    //     }
    //     return solve(0, n-1, stoneValue, dp, prefix);
    // }

    int stoneGameV(vector<int>& stoneValue) { //tabulation
        int n = stoneValue.size();

        vector<int> prefix(n + 1, 0);
        for(int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] + stoneValue[i];

        vector<vector<int>> dp(n, vector<int>(n, 0));

        for(int len = 2; len <= n; len++) {

            for(int l = 0; l + len - 1 < n; l++) {

                int r = l + len - 1;

                for(int k = l; k < r; k++) {

                    int lSum = prefix[k + 1] - prefix[l];
                    int rSum = prefix[r + 1] - prefix[k + 1];

                    if(lSum < rSum) {
                        dp[l][r] = max(
                            dp[l][r],
                            lSum + dp[l][k]
                        );
                    }
                    else if(rSum < lSum) {
                        dp[l][r] = max(
                            dp[l][r],
                            rSum + dp[k + 1][r]
                        );
                    }
                    else {
                        dp[l][r] = max(
                            dp[l][r],
                            lSum + max(
                                dp[l][k],
                                dp[k + 1][r]
                            )
                        );
                    }
                }
            }
        }

        return dp[0][n - 1];
    }
};