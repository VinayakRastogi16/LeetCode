class Solution {
public:

    int tabulation(vector<int>& piles) {

        int n = piles.size();

        vector<int> suffix(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            suffix[i] = piles[i] + suffix[i + 1];
        }

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int i = n - 1; i >= 0; i--) {

            for (int M = n; M >= 1; M--) {

                if (2 * M >= n - i) {
                    dp[i][M] = suffix[i];
                    continue;
                }

                int ans = 0;

                for (int X = 1; X <= 2 * M; X++) {

                    int opponent =
                        dp[i + X][max(M, X)];

                    int current =
                        suffix[i] - opponent;

                    ans = max(ans, current);
                }

                dp[i][M] = ans;
            }
        }

        return dp[0][1];
    }


    int solve(int i, int M, vector<int>& p, vector<int>& suffix, vector<vector<int>>& dp){ //Memoization
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

        // return tabulation(piles);
    }


};