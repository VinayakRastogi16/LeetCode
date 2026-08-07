class Solution {
public:
    const int INF = 1e9;
    int solve(int i, vector<int>& coins, int amt, vector<vector<int>>& dp){
        if(amt == 0) return 0;
        if(i == coins.size()) return INF;
        if(dp[i][amt] != -1)return dp[i][amt];  

        int take = INF;

        if(coins[i]<=amt) take = 1 + solve(i, coins, amt-coins[i], dp);
        int notTake = solve(i+1, coins, amt, dp);

        return dp[i][amt] = min(take, notTake);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        int ans = solve(0, coins, amount, dp);

        return ans == INF? -1: ans;
    }
};