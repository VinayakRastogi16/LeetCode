class Solution {
    
public:

    const int MOD = 1e9+7;
    vector<vector<long long>> vec;

    long long dfs(vector<int>& arr){
        int n = arr.size();
        if(n<2)return 1;
        vector<int> left, right;

        for(int i = 1; i<n; i++){
            if(arr[i]<arr[0]) left.push_back(arr[i]);
            else right.push_back(arr[i]);
        }

        long long res = vec[n-1][left.size()];
        res = res*dfs(left)%MOD;
        res = res*dfs(right)%MOD;

        return res;
    }

    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        vec.assign(n+1, vector<long long>(n+1, 0));

        for(int i = 0; i<=n; i++){
            vec[i][0] = 1;
            for(int j = 1; j<=i; j++){
                vec[i][j] = (vec[i-1][j-1]+vec[i-1][j])%MOD;
            }

        }

        return (dfs(nums)-1+MOD)%MOD;
    }
};