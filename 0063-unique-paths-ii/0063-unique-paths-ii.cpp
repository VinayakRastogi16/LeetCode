class Solution {
public:

    int solve(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dp){
        int m = grid.size();
        int n = grid[0].size();

        if(i >= m || j>=n) return 0;

        if(grid[i][j]==1)return 0;

        if(i == m-1 && j == n-1)return 1;

        if(dp[i][j]!=-1)return dp[i][j];

        int down = solve(grid, i+1, j, dp);
        int right = solve(grid, i, j+1, dp);

        return dp[i][j] = down+right;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> dp(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), -1));
        return solve(obstacleGrid, 0, 0, dp);
    }
};