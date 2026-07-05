class Solution {
public:

    int solve(int i, int j, const string& t1, const string& t2, vector<vector<int>>& dp){
        if(i==t1.size() || j == t2.size())return 0;

        if(dp[i][j]!= -1){
            return dp[i][j];
        }

        if(t1[i]==t2[j])return dp[i][j] = 1+ solve(i+1,j+1, t1, t2, dp);

        return dp[i][j] = max(solve(i+1,j, t1, t2, dp), solve(i, j+1, t1, t2, dp));
    }

    int longestCommonSubsequence(string text1, string text2) {

        vector<vector<int>> dp(text1.size()+1, vector<int>(text2.size(), -1));

        return solve(0,0, text1, text2, dp);
        
    }
};