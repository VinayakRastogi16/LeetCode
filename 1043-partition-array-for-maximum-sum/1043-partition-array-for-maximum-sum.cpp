class Solution {
public:

    int tabulation(vector<int>& arr, int k){
        int n = arr.size();
        vector<int> dp(n+1, 0);

        
        for(int i = n-1; i>=0; i--){
            int maxi = 0;
            for(int j = i; j<min(n, k+i); j++){
                maxi = max(maxi, arr[j]);

                dp[i] = max(dp[i], maxi*(j-i+1)+dp[j+1]);
            }
        }

        return dp[0];

    }

    int solve(int i, int k, vector<int>& arr, vector<int>& dp){
        int n = arr.size();
        if(i == arr.size()) return 0;

        int maxi = 0;
        int cost = 0;

        if(dp[i]!=-1)return dp[i];

        for(int j = i; j<min(n, k+i);j++){
            maxi = max(maxi, arr[j]);

            cost = max(cost, maxi*(j-i+1)+solve(j+1, k, arr, dp));
        }

        return dp[i] = cost;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        // vector<int> dp(arr.size()+1, -1);
        // return solve(0, k, arr, dp);

        return tabulation(arr, k);
    }
};