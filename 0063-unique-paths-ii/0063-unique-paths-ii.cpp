class Solution {
public:

    int tabulation(vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        dp[m-1][n-1] = (grid[m-1][n-1]==1)? 0:1;

        for(int i = m-1; i>=0; i--){
            for(int j =n-1; j>=0; j--){

                if(i == m-1 && j == n-1) continue;

                

                if(grid[i][j] == 1) {
                    dp[i][j] = 0;
                }
                else{

                    long long down = dp[i+1][j];
                    long long right = dp[i][j+1];
                    dp[i][j] = right+down;
                    

                }

            }
        }

        return dp[0][0];
    }

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
        // return solve(obstacleGrid, 0, 0, dp);

        return tabulation(obstacleGrid);
    }
};