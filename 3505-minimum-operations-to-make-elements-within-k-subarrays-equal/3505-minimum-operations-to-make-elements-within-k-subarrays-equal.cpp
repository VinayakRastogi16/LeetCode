class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        multiset<long long> low, high;
        long long sumLow = 0, sumHigh = 0;

        int need = (x + 1) / 2;

        // Maintain the sizes of both halves
        auto rebalance = [&]() {
            while (low.size() > need) {
                long long val = *low.rbegin();
                low.erase(prev(low.end()));
                sumLow -= val;

                high.insert(val);
                sumHigh += val;
            }

            while (low.size() < need && !high.empty()) {
                long long val = *high.begin();
                high.erase(high.begin());
                sumHigh -= val;

                low.insert(val);
                sumLow += val;
            }
        };

        // Insert an element
        auto add = [&](long long val) {
            if (low.empty() || val <= *low.rbegin()) {
                low.insert(val);
                sumLow += val;
            } else {
                high.insert(val);
                sumHigh += val;
            }

            rebalance();
        };

        // Remove one occurrence of an element
        auto remove = [&](long long val) {
            auto it = low.find(val);

            if (it != low.end()) {
                low.erase(it);
                sumLow -= val;
            } else {
                it = high.find(val);
                high.erase(it);
                sumHigh -= val;
            }

            rebalance();
        };

        // Calculate the cost of the current window
        auto getCost = [&]() -> long long {
            long long median = *low.rbegin();

            return median * low.size() - sumLow
                 + sumHigh - median * high.size();
        };

        // Step 1: Calculate costs of all windows
        vector<long long> cost;

        for (int i = 0; i < x; i++) {
            add(nums[i]);
        }

        cost.push_back(getCost());

        for (int i = x; i < n; i++) {
            remove(nums[i - x]);
            add(nums[i]);

            cost.push_back(getCost());
        }

        // Step 2: DP with space optimization
        const long long INF = LLONG_MAX / 4;

        vector<long long> prev(n + 1, 0);
        vector<long long> curr(n + 1, INF);

        for (int j = 1; j <= k; j++) {
            fill(curr.begin(), curr.end(), INF);

            for (int i = 1; i <= n; i++) {

                // Skip current element
                curr[i] = curr[i - 1];

                // Select a window of size x
                if (i >= x && prev[i - x] != INF) {
                    curr[i] = min(
                        curr[i],
                        prev[i - x] + cost[i - x]
                    );
                }
            }

            prev.swap(curr);
        }

        return prev[n];
    }
};