class Solution {
public:

    int solve(int i, int canBuy, int cap, vector<int>& p, vector<vector<vector<int>>>& dp){

        if(i == p.size())return 0;
        if(cap==0)return 0;

        if(dp[i][canBuy][cap]!=-1) return dp[i][canBuy][cap];

        if (canBuy) {
            int buy  = -p[i] + solve(i + 1, 0, cap, p, dp);
            int skip = solve(i + 1, 1, cap, p, dp);

            return dp[i][canBuy][cap] = max(buy, skip);
        }
        else {
            int sell = p[i] + solve(i + 1, 1, cap - 1, p, dp);
            int hold = solve(i + 1, 0, cap, p, dp);

            return dp[i][canBuy][cap] = max(sell, hold);
        }
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return solve(0, 1, 2, prices, dp);
    }
};