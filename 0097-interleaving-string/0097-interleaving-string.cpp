class Solution {
public:

    bool tabulation(const string& s1, const string& s2, const string& s3){


        int n = s1.size(), m = s2.size();
        if (n+m != s3.size()) return false;

        vector<vector<int>> dp(n+1, vector<int>(m+1, false));
        dp[n][m] = true;
        

        for(int i = n; i>=0; i--){
            for(int j = m; j>=0; j--){
                bool ans1 = false;
                bool ans2 = false;
                
                if(i == n && j == m) continue;

                if(i<n && s1[i]==s3[i+j])
                    ans1 = dp[i+1][j];

                if(j<m && s2[j]==s3[i+j])
                    ans2 = dp[i][j+1];

                dp[i][j] = ans1||ans2;
            }
        }

        return dp[0][0];
    }

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
        // vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1, -1));
        // return solve(0, 0, s1, s2, s3, dp);

        return tabulation(s1, s2, s3);
    }
};