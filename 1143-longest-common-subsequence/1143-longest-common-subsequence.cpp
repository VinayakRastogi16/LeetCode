class Solution {
public:

    int tabulation(const string& t1, const string&t2){

        int n = t1.size(), m = t2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        for(int i = n - 1; i >= 0; i--) {
            for(int j = m - 1; j >= 0; j--) {

                if(t1[i] == t2[j]) {
                    dp[i][j] = 1 + dp[i+1][j+1];
                }
                else {
                    dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
                }
            }
        }

        return dp[0][0];
    }

    int solve(int i, int j, const string& t1, const string& t2, vector<vector<int>>& dp){
        if(i==t1.size() || j == t2.size())return 0;

        if(dp[i][j]!= -1){
            return dp[i][j];
        }

        if(t1[i]==t2[j])return dp[i][j] = 1+ solve(i+1,j+1, t1, t2, dp);

        return dp[i][j] = max(solve(i+1,j, t1, t2, dp), solve(i, j+1, t1, t2, dp));
    }

    int longestCommonSubsequence(string text1, string text2) {

        vector<vector<int>> dp(text1.size()+1, vector<int>(text2.size()+1, -1));

        // return solve(0,0, text1, text2, dp);

        return tabulation(text1, text2);
        
    }
};