class Solution {
public:

    bool tabulation(const string& s, vector<string>& w){
        int n = s.size();
        vector<bool> dp(n+1, false);
        dp[n] = true;

        for(int i = n-1; i>=0; i--){
            for(auto& word : w){
                if(s.substr(i, word.length()) == word ){
                    if(dp[i+word.length()]){
                        dp[i] = true;
                        break;
                    }
                }
            }
        }

        return dp[0];
    }

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
        // return solve(0, s, wordDict, dp);
        return tabulation(s, wordDict);
    }
};