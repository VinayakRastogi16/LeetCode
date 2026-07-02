class Solution {
public:
    int solve(vector<int>& coins, int amount, vector<int>& dp){
        if(amount == 0) return 0;

        if(dp[amount] != -1) return dp[amount];

        int ans = INT_MAX;

        for(int i =0; i< coins.size();i++){
            if(amount>=coins[i]){
                int temp = solve(coins, amount - coins[i], dp);

                if(temp!=INT_MAX)
                ans = min(ans, 1+temp);
            }
        }

        return dp[amount] = ans;

    }

    int coinChange2(vector<int>& coins, int amount) {
        if(amount == 0) return 0;

        vector<int> dp(amount+1, -1);

        

        int ans =  solve(coins, amount , dp);

        if(ans == INT_MAX){
            return -1;
        }

        return ans;
    }

    int coinChange(vector<int>& coins, int amount) {

    vector<int> dp(amount + 1, INT_MAX);

    dp[0] = 0;

    for(int i = 1; i <= amount; i++) {

        for(int j = 0; j < coins.size(); j++) {

            if(i >= coins[j] && dp[i - coins[j]] != INT_MAX) {

                dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
            }
        }
    }

    return (dp[amount] == INT_MAX) ? -1 : dp[amount];
}
};