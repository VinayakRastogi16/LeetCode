class Solution {
public:
    static constexpr int INF = 1000000000;

    int tabulation(vector<vector<int>>& m){
        int n = m.size();



        vector<vector<int>> dp(n, vector<int>(n,0));

        for(int j = 0; j<n; j++){
            dp[n-1][j] = m[n-1][j];
        }

        for(int i = n-2; i>=0; i--){
            for(int j = 0; j<n; j++){

                int ans = m[i][j] + dp[i+1][j];

                if(j>0) ans = min(ans, m[i][j]+dp[i+1][j-1]);

                if(j<n-1) ans = min(ans, m[i][j]+dp[i+1][j+1]);

                dp[i][j] = ans;
            }

        }

        int ans = INF;
        for(int j = 0; j < n; j++)
        ans = min(ans, dp[0][j]);

        return ans;
    }

    int solve(int i, int j, vector<vector<int>>& m, vector<vector<int>>& dp) {
        int n = m.size();

        if (j < 0 || j >= n)
            return INF;

        if (dp[i][j] != INF)
            return dp[i][j];

        if (i == n - 1)
            return dp[i][j] = m[i][j];

        int left  = solve(i + 1, j - 1, m, dp);
        int down  = solve(i + 1, j,     m, dp);
        int right = solve(i + 1, j + 1, m, dp);

        return dp[i][j] = m[i][j] + min(left, min(down, right));
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        vector<vector<int>> dp(n, vector<int>(n, INF));

        int ans = INF;
        for (int j = 0; j < n; j++)
            ans = min(ans, solve(0, j, matrix, dp));

        // return ans;
        return tabulation(matrix);
    }
};