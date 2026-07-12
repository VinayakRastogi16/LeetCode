class Solution {
public:

    int tabulation(const string& s){
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for(int i = 0; i<n; i++){
            dp[i][i] = 1;
        }

        for(int i = n-1; i>=0; i--){
            for(int j = i+1; j< n; j++){
                if(s[i]==s[j]){
                    dp[i][j] = 2+dp[i+1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }    
            }
        }

        return dp[0][n-1];

    }

    int solve(int i, int j, const string& s, vector<vector<int>>& dp){
        if(i>j) return 0;
        if(i == j) return 1;

        if(dp[i][j]!=-1) return dp[i][j];

        if(s[i]==s[j])
            return dp[i][j] = 2+solve(i+1, j-1, s, dp);

        return dp[i][j] = max(solve(i+1, j, s, dp), solve(i, j-1, s, dp));
    }

    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), -1));
        // return solve(0, s.size()-1, s, dp);
        return tabulation(s);
    }
};