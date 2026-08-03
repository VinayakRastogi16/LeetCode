class Solution {
public:

    int solve(int i, vector<int>& st, int n, vector<int>& dp){
        if(i == n)
            return 0;

        int ans = INT_MIN;
        int sum = 0;

        if(dp[i] != INT_MIN) return dp[i];

        for(int k = 0; k <3&& i+k<n; k++){
            sum +=st[i+k];
            ans = max(ans, sum-solve(i+k+1, st, n, dp));
        }

        return dp[i] = ans;
    }

    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(n, INT_MIN);
        int diff = solve(0, stoneValue, n, dp);

        if (diff > 0)
            return "Alice";
        else if (diff < 0)
            return "Bob";
        else
            return "Tie";
    }
};