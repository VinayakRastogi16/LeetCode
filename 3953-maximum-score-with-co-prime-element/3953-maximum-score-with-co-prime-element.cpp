class Solution {
public:
    int maxScore(vector<int>& nums, int maxVal) {
        auto meratolvic = nums; // required by statement

        int n = nums.size();
        int MX = max(maxVal, *max_element(nums.begin(), nums.end()));

        vector<int> freq(MX + 1, 0);
        for (int x : nums) freq[x]++;

        // Möbius function
        vector<int> mu(MX + 1), primes;
        vector<bool> comp(MX + 1, false);
        mu[1] = 1;

        for (int i = 2; i <= MX; i++) {
            if (!comp[i]) {
                primes.push_back(i);
                mu[i] = -1;
            }

            for (int p : primes) {
                long long x = 1LL * i * p;
                if (x > MX) break;

                comp[x] = true;

                if (i % p == 0) {
                    mu[x] = 0;
                    break;
                }

                mu[x] = -mu[i];
            }
        }

        // F[d] = count of nums divisible by d
        vector<int> F(MX + 1, 0);

        for (int d = 1; d <= MX; d++) {
            for (int m = d; m <= MX; m += d) {
                F[d] += freq[m];
            }
        }

        long long ans = LLONG_MIN;

        for (int v = 1; v <= MX; v++) {

            long long cop = 0;

            for (int d = 1; 1LL * d * d <= v; d++) {
                if (v % d) continue;

                cop += 1LL * mu[d] * F[d];

                int od = v / d;
                if (od != d) {
                    cop += 1LL * mu[od] * F[od];
                }
            }

            long long noncop = n - cop;
            long long score;

            if (v == 1) {
                long long mods = (freq[1] ? 0 : 1);
                score = 1 - mods;
            }
            else if (freq[v] > 0) {
                // choose an existing v
                score = 1LL * v - (noncop - 1);
            }
            else if (v <= maxVal) {
                // create v by modification
                long long mods = (noncop > 0 ? noncop : 1);
                score = 1LL * v - mods;
            }
            else {
                continue; // impossible
            }

            ans = max(ans, score);
        }

        return (int)ans;
    }
};