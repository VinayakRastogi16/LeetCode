class Solution {
public:

    int tabulation(int m, int n){
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        dp[m-1][n-1] = 1;

        for(int i = m-1; i>=0; i--){
            for(int j = n-1; j>=0; j--){
                if(i == m-1 && j == n-1) continue;

                int down = dp[i+1][j];
                int right  = dp[i][j+1];

                dp[i][j] = down+right;
            }
        }

        return dp[0][0];

    }

    int solve(int m, int n, int i, int j, vector<vector<int>>& dp){
        if(i >= m || j >= n)return 0;

        if(i==m-1 && j==n-1) return dp[i][j] = 1;

        if(dp[i][j]!=-1) return dp[i][j];

        int down = solve(m, n, i+1, j, dp);
        int right = solve(m, n, i, j+1, dp);

        return dp[i][j] = down+right;
    }

    int uniquePaths(int m, int n) {

        // vector<vector<int>> dp(m+1, vector<int>(n+1, -1));

        // return solve(m, n, 0, 0, dp);

        return tabulation(m, n);
    }
};