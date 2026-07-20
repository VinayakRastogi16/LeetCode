class Solution {
public:

    int tabulation(int k, vector<int>& p){
        int n = p.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1, 0)));

        for(int i = n-1; i>=0; i--){
            for(int canBuy = 0; canBuy<=1; canBuy++){
                for(int cap = 1; cap<= k; cap++){
                    if (canBuy) {
                        dp[i][canBuy][cap] =
                            max(-p[i] + dp[i+1][0][cap],
                                dp[i+1][1][cap]);
                    }
                    else {
                        dp[i][canBuy][cap] =
                            max(p[i] + dp[i+1][1][cap-1],
                                dp[i+1][0][cap]);
                    }
                }
            }
        }

        return dp[0][1][k];
    } 

    int solve(int i, bool canBuy, int cap, vector<int>& p, vector<vector<vector<int>>>& dp){
        if(i == p.size()) return 0;
        if(cap == 0) return 0;

        if(dp[i][canBuy][cap]!=-1) return dp[i][canBuy][cap];

        if(canBuy){
            int buy = -p[i]+solve(i+1, 0, cap, p, dp);
            int skip = solve(i+1, 1, cap, p, dp);

            return dp[i][canBuy][cap] = max(buy, skip);

        }else{
            int sell = p[i]+solve(i+1, 1, cap-1, p, dp);
            int hold = solve(i+1, 0, cap, p, dp);

            return dp[i][canBuy][cap] = max(sell, hold);
        }
    }

    int maxProfit(int k, vector<int>& prices) {
        // int n = prices.size();
        // vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k+1, -1)));
        // return solve(0, 1, k, prices, dp);
        return tabulation(k, prices);
    }
};