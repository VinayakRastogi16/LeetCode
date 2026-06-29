class Solution {
public:

    int tabulation(vector<int>& cost, int n){
        vector<int> dp(n);

        dp[0]=cost[0];
        dp[1]=cost[1];

        for(int i = 2; i<n ; i++){
            dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
        }

        return min(dp[n-1],dp[n-2]);
    }

    int solve(vector<int>& cost, int i, vector<int>& dp){
        if(i == 0 || i==1) return cost[i];

        if(dp[i] != -1)
         return dp[i];

        int ans =  cost[i]+ min(solve(cost, i-1, dp), solve(cost, i-2, dp));

        return dp[i] = ans;
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        vector<int> dp(n,-1);
        // return min(solve(cost, n-1, dp), solve(cost, n-2, dp));

        return tabulation(cost, n);
    }
};