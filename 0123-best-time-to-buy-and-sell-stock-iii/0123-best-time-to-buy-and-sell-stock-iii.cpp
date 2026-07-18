class Solution {
public:

    int tabulation(vector<int>& p){
        int n = p.size();

        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));

        for(int i = n-1; i>=0; i--){
            for(int j = 0; j<=1; j++){
                for(int k = 1; k <= 2; k++){

                    if(j)
                        dp[i][j][k] = max(-p[i] + dp[i+1][0][k], dp[i+1][1][k]);
                    else
                        dp[i][j][k] = max(p[i]+dp[i+1][1][k-1], dp[i+1][0][k]);
                }
            }
        }
        return dp[0][1][2];
    }

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
        // return solve(0, 1, 2, prices, dp);
        return tabulation(prices);
    }
};