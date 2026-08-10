class Solution {
public:
    bool tabulation(int n){
        vector<bool> dp(n+1, false);

        dp[0] = false;

        for(int i = 1; i<=n; i++){
            for(int j=1; j*j<=i; j++){
                if(dp[i-j*j]==false){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }

    bool solve(int n, vector<int>& dp){
        if(n==0) return false;
        if(dp[n] !=-1)return dp[n];
        for(int j = 1; j*j<=n; j++){
            if(!solve(n-j*j, dp))return dp[n] = true;   
        }

        return dp[n] = false;
    }

    bool winnerSquareGame(int n) {
        // vector<int> dp(n+1, -1);
        // return solve(n, dp);

        return tabulation(n);
    }
};