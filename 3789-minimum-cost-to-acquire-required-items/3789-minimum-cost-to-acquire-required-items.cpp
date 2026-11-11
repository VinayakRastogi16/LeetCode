class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth,
                          int need1, int need2) {

        long long common = min(need1, need2);

        long long remaining1 = need1 - common;
        long long remaining2 = need2 - common;

        long long ans = common * min(costBoth, cost1 + cost2);

        ans += remaining1 * min(cost1, costBoth);

        ans += remaining2 * min(cost2, costBoth);

        return ans;
    }
};
