class Solution {
public:

    int solve(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dp){

        int m = grid.size();
        int n = grid[0].size();

        if(i== m-1&& j==n-1)return grid[i][j];

        if(i>=m||j>=n) return INT_MAX;

        if(dp[i][j]!=-1)return dp[i][j];

        int down = solve(grid, i+1, j, dp);
        int right = solve(grid, i, j+1, dp);

        int ans = min(down, right);

        if(ans==INT_MAX)return INT_MAX;

        return dp[i][j] = grid[i][j]+ans;
    }

    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size()+1, vector<int>(grid[0].size()+1, -1));
        return solve(grid, 0, 0, dp);
    }
};