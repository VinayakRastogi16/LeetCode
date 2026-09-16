class Solution {
public:

    int M = 1e9+7; 
    vector<vector<int>> dp;

    int tabulation(int n, int K){
        vector<vector<int>> t(n+1, vector<int>(n+1));

        for(int i = 0; i<n; i++){
            t[0][i] = 1;
        }

        for(int k = 1; k<=K; k++){
            
            vector<int> prevRow(n+1, 0);

            for(int x = n-1; x>=0; x--){
                prevRow[x] = (prevRow[x+1]+t[k-1][x])%M;
            }

            for(int i = n-1; i>=0; i--){
                int take = prevRow[i+1];
                int skip = t[k][i+1]%M;

                t[k][i] = (take+skip)%M;
            }
        }
        return t[K][0];
    }

    // int solve(int n, int k, int i){
    //     if(k==0)return 1;

    //     if(i>=n)return 0;

    //     if(dp[k][i]!=-1)return dp[k][i];

    //     long long take = 0;
    //     for(int j = i+1; j<n; j++){
    //         take = (take+solve(n, k-1, j));
    //     }

    //     long long skip = solve(n, k, i+1);

    //     return dp[k][i] = (take+skip)%M;

    // }

    int numberOfSets(int n, int k) {
        // dp.assign(n+1, vector<int>(n+1, -1));
        // return solve(n, k, 0)%M;

        return tabulation(n, k);
    }
};