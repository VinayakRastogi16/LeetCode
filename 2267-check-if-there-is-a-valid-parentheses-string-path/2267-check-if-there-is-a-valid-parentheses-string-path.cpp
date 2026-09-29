class Solution {
public:
    int m;
    int n;

    bool solve(int i, int j, int cnt, vector<vector<char>>& grid, vector<vector<vector<int>>>& dp){
        cnt += (grid[i][j]=='(')? 1:-1;

         if(cnt<0)return false;

        if(dp[i][j][cnt]!=-1)return dp[i][j][cnt];

        if(i==m-1 && j==n-1) return dp[i][j][cnt] = cnt==0;

        if(i+1<m){
            if(solve(i+1, j, cnt, grid, dp)){
                return dp[i][j][cnt] = true;
            }
        }

        if(j+1<n){
            if(solve(i, j+1, cnt, grid, dp)){
                return dp[i][j][cnt] = true;
            }
        }

        return dp[i][j][cnt] = false;
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        if((m+n-1)%2==1)return false;
        if(grid[0][0]==')' || grid[m-1][n-1] == '(')return false;

        vector<vector<vector<int>>> dp(m+1, vector<vector<int>>(n+1, vector<int>(m+n+1, -1)));

        return solve(0, 0, 0, grid, dp);
    }
};