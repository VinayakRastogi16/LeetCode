class Solution {
public:

    int solve(int i, int j, int n, vector<int>& cuts, vector<vector<int>>& dp){
        if(j-i ==1)return 0;

        if(dp[i][j]!=INT_MAX) return dp[i][j];

        int ans = INT_MAX;

        for(int k = i+1; k<j;k++){
            int cut = (cuts[j]-cuts[i]);
            ans = min(ans, solve(i, k, n, cuts, dp)+solve(k, j, n, cuts, dp)+ cut);
        }

        return dp[i][j] = ans;
    }

    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        int m = cuts.size();
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(m, vector<int>(m, INT_MAX));
        return solve(0, cuts.size()-1, n, cuts, dp);
    }
};