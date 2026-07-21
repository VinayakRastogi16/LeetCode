class Solution {
public:

    bool solve(int i, int j, const string& s1, const string& s2, const string& s3, vector<vector<int>>& dp){
        bool ans1 = false;
        bool ans2 = false;

        if (s1.size() + s2.size() != s3.size()) return false;

        if(i ==s1.size() && j ==s2.size()) return true;

        if(dp[i][j]!=-1) return dp[i][j];


        if(i < s1.size() && s1[i]==s3[i+j]){
            ans1 = solve(i+1, j, s1, s2, s3, dp);
        }

        if(j < s2.size() && s2[j]==s3[i+j]){
            ans2 = solve(i, j+1, s1, s2, s3, dp);
        }

        return dp[i][j] = (ans1||ans2);
    }

    bool isInterleave(string s1, string s2, string s3) {
        vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1, -1));
        return solve(0, 0, s1, s2, s3, dp);
    }
};