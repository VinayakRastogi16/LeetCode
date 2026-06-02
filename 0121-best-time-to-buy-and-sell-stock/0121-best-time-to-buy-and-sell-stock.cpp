class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> bestBuy(prices.size());
        bestBuy[0] = INT_MAX;
        int profit = 0;

        for(int i = 1; i<prices.size(); i++){
            bestBuy[i] = min(bestBuy[i-1], prices[i-1]);
        }

        for(int i = 0; i<prices.size(); i++){
            profit = max(profit, (prices[i]-bestBuy[i]));
        }

        return profit;
    }
};