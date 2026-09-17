class Solution {
public:
    int k;
    int n;

    int solve(vector<int>& arr, int i, int count, vector<vector<int>>& dp, vector<int>& end) {
        if (count == 0)
            return 0;

        if (i >= n)
            return 1e9;

        if(dp[i][count]!=-1)return dp[i][count];

        int skip = solve(arr, i + 1, count, dp, end);

        int take = 1e9;

        if(end[i]!=-1){
            int len = end[i]-i+1;

            int next = solve(arr, end[i]+1, count-1, dp, end);

            if(next!=1e9) take = len+next;
        }

        return dp[i][count] = min(skip, take);
    }

    int minSumOfLengths(vector<int>& arr, int target) {
        k = target;
        n = arr.size();

        vector<int> end(n, -1);

        int l = 0;
        long long sum = 0;

        for(int r = 0; r<n;r++){
            sum += arr[r];

            while(l<=r && sum>target){
                sum -= arr[l];
                l++;
            }

            if(sum == k){
                end[l] = r;
            }
        }


        vector<vector<int>> dp(n, vector<int>(3, -1));
        int ans = solve(arr, 0, 2, dp, end);
        return ans == 1e9 ? -1 : ans;
    }
};