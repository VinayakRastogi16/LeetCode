class Solution {
public:

    int tabulation(const string& w1, const string& w2){
        int n = w1.size();
        int m = w2.size();
        vector<vector<int>> dp(w1.size()+1, vector<int>(w2.size()+1,0));

        for(int i = 0; i<=n; i++){
            dp[i][m] = n-i;
        }

        for(int j = 0; j<=m; j++){
            dp[n][j] = m-j;
        }


        for(int i = n-1; i>=0; i--){
            for(int j = m-1; j>=0; j--){
                if(w1[i]==w2[j]) {
                    dp[i][j] = dp[i+1][j+1];
                }else{
                    int insert = 1+dp[i][j+1];
                    int replace = 1+dp[i+1][j+1];
                    int del = 1+dp[i+1][j];
                    

                    dp[i][j] = min({insert, replace, del});

                }
            }
        }

        return dp[0][0];
    }

    int solve(int i, int j, const string& w1, const string& w2, vector<vector<int>>& dp){

        if(i == w1.size()) return w2.size()-j;

        if(j==w2.size()) return w1.size()-i;

        if(w1[i] == w2[j]) return dp[i][j] = solve(i+1, j+1, w1, w2, dp);

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int insert = 1+solve(i, j+1, w1, w2, dp);
        int replace = 1+solve(i+1, j+1, w1, w2, dp);
        int del = 1+solve(i+1, j, w1, w2, dp);

        return dp[i][j] = min({insert, del, replace});
    }

    int minDistance(string word1, string word2) {

        vector<vector<int>> dp(word1.size()+1, vector<int>(word2.size()+1, -1));

        // return solve(0, 0, word1, word2, dp); ##memoization
        return tabulation(word1, word2); //Tabulation
    }
};