class Solution {
public:
    long long maxTotal(vector<int>& nums, string s) {
        int n = nums.size();
        const long long NEG = -1e18;

        vector<vector<long long>> dp(n+1, vector<long long>(2,NEG));
        dp[0][0]= 0;

        for(int i = 0; i< n; i++){

            dp[i+1][0] = max(dp[i+1][0], dp[i][0]);
            dp[i+1][0] = max(dp[i+1][0], dp[i][1]);

            if(s[i] == '1' && dp[i][0] != NEG){
                dp[i+1][0] =max(dp[i+1][0], dp[i][0]+nums[i]);
                
            }

            if(i+1 < n && s[i+1] == '1'){

                if(dp[i][0]!=NEG){
                    dp[i+1][1] = max(dp[i+1][1], dp[i][0]+nums[i]);
                }

                if(dp[i][1]!=NEG){
                    dp[i+1][1] = max(dp[i+1][1], dp[i][1]+nums[i]);
                }
            }
        }

        return max(dp[n][0], dp[n][1]);
    }
};