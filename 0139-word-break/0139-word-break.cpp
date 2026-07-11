class Solution {
public:

    bool solve(int i, const string& s,  vector<string>& wordDict, vector<int>& dp){
        if(i == s.size()) return true;

        if(dp[i]!=-1) return dp[i];

        for(int j = 0; j<wordDict.size(); j++){
            if(s.substr(i, wordDict[j].length()) == wordDict[j]){
                if(solve(i+wordDict[j].length(), s, wordDict, dp)){
                    return dp[i] = true;
                }
            }
        }

        return dp[i] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.size(), -1);
        return solve(0, s, wordDict, dp);
    }
};