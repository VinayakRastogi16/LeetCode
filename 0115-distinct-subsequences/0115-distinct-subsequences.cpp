class Solution {
public:

    long long tabulation(const string s, const string& t){
        int m = s.size(), n = t.size();

        vector<vector<long long>> dp(m+1, vector<long long>(n+1, 0));
        for(int i = 0; i<=m; i++){
            dp[i][n] = 1;
        }


        for(int i = m-1; i>=0; i--){
            for(int j = n-1; j>=0; j--){
                const long long LIM = INT_MAX;
                if(s[i]==t[j]) dp[i][j] = min(LIM,dp[i+1][j]+dp[i+1][j+1]);
                else dp[i][j] = dp[i+1][j];

            }
        }

        return dp[0][0];
    }

    long long solve(int i, int j, const string& s, const string& t, vector<vector<long long>>& dp){
        if(j == t.size()) return 1;
        if(i == s.size()) return 0;

        if(dp[i][j] != -1)return dp[i][j];

        if(s[i]==t[j]) return dp[i][j] = solve(i+1, j+1, s, t, dp)+solve(i+1, j, s, t, dp);

        return dp[i][j] = solve(i+1, j, s, t, dp);
    }

    int numDistinct(string s, string t) {
        vector<vector<long long>> dp(s.size(), vector<long long>(t.size(), -1));
        // return solve(0, 0, s, t, dp);
        return (int)tabulation(s, t);
    }
};