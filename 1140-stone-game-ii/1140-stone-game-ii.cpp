class Solution {
public:

    int solve(int i, int M, vector<int>& p, vector<int>& suffix, vector<vector<int>>& dp){
        int n = p.size();
        if(2*M>=n-i) return suffix[i];

        if(dp[i][M]!=-1)return dp[i][M];

        int ans = 0;

        for(int X = 1; X<=2*M; X++){
            int op = solve(i+X, max(X, M), p, suffix, dp);

            int current = suffix[i] - op;

            ans = max(current, ans);
        }

        return dp[i][M] = ans;
    }

    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<int> suffix(n+1, 0);
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        for (int i = n - 1; i >= 0; i--) {
            suffix[i] = piles[i] + suffix[i + 1];
        }
        return solve(0, 1, piles, suffix, dp);
    }
};