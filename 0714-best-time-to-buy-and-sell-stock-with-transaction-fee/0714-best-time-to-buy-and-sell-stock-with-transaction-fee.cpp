class Solution {
public:

    int solve(int i, bool canBuy, int fee, const vector<int>& p, vector<vector<int>>& dp){

        if(i == p.size()) return 0;

        if(dp[i][canBuy] != -1)return dp[i][canBuy];

        if(canBuy){
            int buy = -p[i]+solve(i+1, 0, fee, p, dp);
            int skip = solve(i+1, 1, fee, p, dp);

            return dp[i][canBuy] = max(buy, skip);

        }else{
            int sell = p[i]-fee + solve(i+1, 1, fee, p, dp);
            int hold = solve(i+1, 0, fee, p, dp);

            return dp[i][canBuy] = max(sell, hold);
        }
    }

    int maxProfit(vector<int>& prices, int fee) {

        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));

        return solve(0, 1, fee, prices, dp);
    }
};