class Solution {
public:

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

        return solve(0, 0, word1, word2, dp);
    }
};