class Solution {
public:
    const int INF = 1e9;

    int tabulation(vector<int>& coins, int amount){
        vector<int> dp(amount+1, INT_MAX);

        dp[0] = 0;

        for(int i = 1; i<=amount; i++){
            for(int j = 0; j<coins.size(); j++){
                if(i>=coins[j]&&dp[i-coins[j]] != INT_MAX){
                    dp[i] = min(dp[i], 1+dp[i-coins[j]]);
                }
            }
        }

        return (dp[amount] == INT_MAX)?-1:dp[amount];

    }

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
        // int n = coins.size();
        // vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        // int ans = solve(0, coins, amount, dp);

        int ans = tabulation(coins, amount);

        return ans;
    }
};