class Solution {
public:

    int tabulation(const vector<int>& p, int fee){
        int n = p.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));

        for(int i = n-1; i>=0; i--){
            dp[i][1] = max(-p[i]+dp[i+1][0], dp[i+1][1]);

            dp[i][0] = max(p[i]-fee+dp[i+1][1], dp[i+1][0]);
        }
        return dp[0][1];
    }

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

        // return solve(0, 1, fee, prices, dp);

        return tabulation(prices, fee);
    }
};