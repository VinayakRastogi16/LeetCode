class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(n + 1, false));

        dp[n][0] = true;

        for (int i = n-1; i >= 0; i--) {
            for (int op = 0; op <= n; op++) {
                bool isValid = false;

                if (s[i] == '*') {
                    isValid |= dp[i + 1][op + 1];
                    isValid |= dp[i + 1][op];
                    if (op > 0) {
                        isValid |= dp[i + 1][op - 1];
                    }
                } else if (s[i] == '(') {
                    isValid |= dp[i + 1][op + 1];
                } else if (op > 0) {
                    isValid |= dp[i + 1][op - 1];
                }
                dp[i][op] = isValid;
            }
        }

        return dp[0][0];
    }
};