class Solution {
public:

    int solve(int i, bool canBuy, vector<int>& p, vector<vector<int>>& dp){
        if(i >= p.size()) return 0;

        if(dp[i][canBuy]!=-1) return dp[i][canBuy];

        if(canBuy){
            int buy = -p[i]+ solve(i+1, 0, p, dp);

            int skip = solve(i+1, 1, p, dp);

            return  dp[i][canBuy] = max(buy,skip);

        }else{
            int sell = p[i]+solve(i+2, 1, p, dp);

            int hold = solve(i+1, 0, p, dp);
            return dp[i][canBuy] = max(hold, sell);
        }
    }

    int maxProfit(vector<int>& prices) {
        bool canBuy = 1;
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return solve(0, canBuy, prices, dp);
    }
};