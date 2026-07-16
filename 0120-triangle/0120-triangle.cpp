class Solution {
public:

    int tabulation(vector<vector<int>>& t){
        int n = t.size();

        vector<vector<int>> dp(n, vector<int>(n, 0));

        for(int i = 0; i<n; i++){
            dp[n-1][i] = t[n-1][i];
        }

        for(int i = n-2; i>=0; i--){
            for(int j = 0; j <= i; j++){
                dp[i][j] = t[i][j]+min(dp[i+1][j], dp[i+1][j+1]);
            }
        }

        return dp[0][0];
    }

    int solve(int i, int j, vector<vector<int>>& triangle,
              vector<vector<int>>& dp) {

        if (dp[i][j] != INT_MAX)
            return dp[i][j];

        if (i == triangle.size() - 1)
            return dp[i][j] = triangle[i][j];

        return dp[i][j] = triangle[i][j] +
               min(solve(i + 1, j, triangle, dp),
                   solve(i + 1, j + 1, triangle, dp));
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        // return solve(0, 0, triangle, dp);
        return tabulation(triangle);
    }
};