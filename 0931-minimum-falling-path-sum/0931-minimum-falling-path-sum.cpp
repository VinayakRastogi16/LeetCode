class Solution {
public:
    static constexpr int INF = 1000000000;

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

        return ans;
    }
};