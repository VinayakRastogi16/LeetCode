class Solution {
public:
    
    int solve(int i, int j, vector<vector<char>>& m, vector<vector<int>>& dp){

        int l = m.size(), n = m[0].size();

        if(i>=l || j>=n) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        if(m[i][j] == '0') return dp[i][j] = 0;

        return dp[i][j] = 1 + min({solve(i+1, j, m, dp), solve(i,j+1,m, dp), solve(i+1, j+1, m, dp)});
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        
        int m = matrix.size(), n = matrix[0].size();

        int maxSide = 0;

        vector<vector<int>> dp(m, vector<int>(n, -1));

        for(int i = 0; i<m;i++){
            for(int j = 0; j<n; j++){
                maxSide = max(maxSide, solve(i, j, matrix, dp));
            }
        }



        return maxSide* maxSide;
    }
};