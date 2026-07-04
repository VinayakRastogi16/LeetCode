class Solution {
public:

    // const long long MOD = 1e9+7;

    int tabulation(int amount, vector<int>& coins){
        int n = coins.size();

        vector<vector<long long>> dp(n+1, vector<long long>(amount+1,0));


        for(int i = 0; i<=n; i++){
            dp[i][0] = 1;

        }

         const long long CAP = 4e18;

        for(int i = n-1; i>=0; i--){
            for(int amt = 1; amt<=amount; amt++){
                long long take = 0;

                if(amt>=coins[i]){
                    take = dp[i][amt - coins[i]];
                }

                long long notTake = dp[i+1][amt];

                if(take > CAP - notTake){
                    dp[i][amt] = CAP;
                } else {
                    dp[i][amt] = take + notTake;
                }
            }

        }

        return (int)dp[0][amount];
    }

    int solve(int i, int amount, vector<int>& coins, vector<vector<int>>& dp){
        if(amount == 0) return 1;

        if(i == coins.size()) return 0;

        if(dp[i][amount] != -1){
            return dp[i][amount];
        }

        int take = 0;

        
        if(amount>=coins[i])
            take = solve(i, amount - coins[i], coins, dp);

        int notTake = solve(i+1, amount, coins, dp);

        return dp[i][amount] = take+notTake;
    }

    int change(int amount, vector<int>& coins) {
        // vector<vector<int>> dp(coins.size()+1, vector<int>(amount+1,-1));

        // return solve(0, amount, coins, dp);

        return tabulation(amount, coins);
    }
};