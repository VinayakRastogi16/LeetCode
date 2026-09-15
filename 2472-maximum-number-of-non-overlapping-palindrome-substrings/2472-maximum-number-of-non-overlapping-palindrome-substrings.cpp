class Solution {
public:
    int n;

    bool isPalindrome(const string& s, int i, int j){
        while(i<j){
            if(s[i++]!=s[j--])return false;
        }
        return true;
    }

    // int solve(string& s, int k, int i, int j, vector<vector<int>>& dp){
    //     if(i>=n||j>=n) return 0;

    //     if(dp[i][j]!=-1)return dp[i][j];

    //     if(isPalindrome(s, i, j)){
    //         int take = 1+solve(s, k, j+1, j+k, dp);
    //         int slide = solve(s, k, i+1, j+1, dp);
    //         int grow = solve(s, k, i, j+1, dp);

    //         return dp[i][j] = max({take, grow, slide});
    //     }

    //     int slide = solve(s, k, i+1, j+1, dp);
    //     int grow = solve(s, k, i, j+1, dp);

    //     return dp[i][j] = max(slide, grow);
        
    // }

    int tabulation(string& s, int k){
        if(k==1)return n;

        vector<vector<int>> dp(n+1, vector<int>(n+1));

        for(int i = n-1; i>=0; i--){
            for(int j = n-1; j>=0; j--){
                if(isPalindrome(s, i, j)){
                    int take = 1+(j+k <= n ? dp[j+1][j+k]:0);
                    int grow = dp[i][j+1];
                    int slide = dp[i+1][j+1];

                    dp[i][j] = max({take, grow, slide});
                }

                int grow = dp[i][j+1];
                int slide = dp[i+1][j+1];

                dp[i][j] = max({dp[i][j], grow, slide});
            }
        }

        return dp[0][k-1];
    }

    int maxPalindromes(string s, int k) {

        n = s.length();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        // return solve(s, k, 0, k-1, dp);
        return tabulation(s, k);

    }
};