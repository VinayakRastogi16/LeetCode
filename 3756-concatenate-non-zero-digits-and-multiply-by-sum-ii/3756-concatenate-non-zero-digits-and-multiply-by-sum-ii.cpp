class Solution {
public:
    static const int MOD = 1e9 + 7;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();

        // pow10[i] = 10^i % MOD
        vector<long long> pow10(n + 1, 1);
        for (int i = 1; i <= n; i++)
            pow10[i] = (pow10[i - 1] * 10) % MOD;

        // cnt[i] = number of non-zero digits in s[0..i-1]
        vector<int> cnt(n + 1, 0);

        // digitSum[i] = sum of non-zero digits in s[0..i-1]
        vector<long long> digitSum(n + 1, 0);

        // pref[i] = concatenated value of non-zero digits in s[0..i-1]
        vector<long long> pref(n + 1, 0);

        for (int i = 0; i < n; i++) {
            cnt[i + 1] = cnt[i];
            digitSum[i + 1] = digitSum[i];
            pref[i + 1] = pref[i];

            if (s[i] != '0') {
                int d = s[i] - '0';
                cnt[i + 1]++;
                digitSum[i + 1] += d;
                pref[i + 1] = (pref[i] * 10 + d) % MOD;
            }
        }

        vector<int> ans;

        for (auto &q : queries) {
            int l = q[0], r = q[1];

            int k = cnt[r + 1] - cnt[l];
            long long sum = digitSum[r + 1] - digitSum[l];

            long long x =
                (pref[r + 1] -
                 pref[l] * pow10[k] % MOD +
                 MOD) % MOD;

            ans.push_back((x * (sum % MOD)) % MOD);
        }

        return ans;
    }
};