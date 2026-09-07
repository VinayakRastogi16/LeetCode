class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD = 1e9 + 7;
        int n = s.size();
        vector<long long> dp(n + 1, 0);

        dp[0] = 1;

        vector<int> last(26, -1);

        for (int i = 1; i <= n; i++) {
            char c = s[i - 1];

            dp[i] = (2 * dp[i - 1]) % MOD;

            int j = last[c - 'a'];

            if (j != -1) {
                dp[i] = (dp[i] - dp[j] + MOD) % MOD;
            }

            last[c - 'a'] = i - 1;
        }

        return (dp[n] - 1 + MOD) % MOD;
    }
};