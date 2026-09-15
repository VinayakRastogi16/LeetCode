class Solution {
public:
    int n;
    vector<vector<bool>> isPalindrome;
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
                if(isPalindrome[i][j]){
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

        isPalindrome.assign(n+1, vector<bool>(n+1, false));

        for(int L = 1; L<=n; L++){
            for(int i = 0; i+L<=n; i++){
                int j = i+L-1;

                if(i==j){
                    isPalindrome[i][j] = true;
                }else if(i+1 == j){
                    isPalindrome[i][j] = (s[i]==s[j]);
                }else{
                    isPalindrome[i][j] = ((s[i]==s[j]) && isPalindrome[i+1][j-1]);
                }
            }
        }

        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        // return solve(s, k, 0, k-1, dp);
        return tabulation(s, k);

    }
};