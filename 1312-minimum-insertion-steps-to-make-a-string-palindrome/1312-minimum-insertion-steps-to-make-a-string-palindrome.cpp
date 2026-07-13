class Solution {
public:

    int solve(int i, int j, const string& s, vector<vector<int>>& dp){
        if(i>=j) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i]==s[j]) return dp[i][j] = solve(i+1, j-1, s, dp);

        return dp[i][j] = 1+min(solve(i, j-1, s, dp), solve(i+1, j, s, dp));
    }

    int minInsertions(string s) {

        vector<vector<int>> dp(s.size(), vector<int>(s.size(), -1));

        return solve(0, s.size()-1, s, dp);
    }
};