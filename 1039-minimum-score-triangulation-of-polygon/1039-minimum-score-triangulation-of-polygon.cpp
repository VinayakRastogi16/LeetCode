class Solution {
public:

    int tabulation(vector<int>& val){
        int n = val.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for(int l = 3; l<=n; l++){
            for(int i = 0; i+l-1<n; i++){
                int j = i+l-1;
                dp[i][j] = INT_MAX;

                    for(int k= i+1; k<j; k++){
                        dp[i][j] = min(dp[i][j], dp[i][k]+val[i]*val[j]*val[k]+dp[k][j]);
                    }
            }
        }

        return dp[0][n-1];
    }


    int solve(int i, int j, vector<int>& val, vector<vector<int>>& dp){
        if(j-i<2) return 0;

        if(dp[i][j]!=-1)return dp[i][j];

        int ans = INT_MAX;

        for(int k = i+1; k<j; k++){
            ans= min(ans, solve(i, k, val, dp)+val[i]*val[k]*val[j]+solve(k, j, val, dp));
        }

        return dp[i][j] = ans;
    }

    int minScoreTriangulation(vector<int>& values) {
        return tabulation(values);
        // int n = values.size();
        // vector<vector<int>> dp(n, vector<int>(n, -1));
        // return solve(0, n-1, values, dp);

       
    }
};