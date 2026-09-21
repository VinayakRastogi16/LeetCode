class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n = nums.size();

        vector<long long> res(k, 0);
        vector<long long>prevCnt(k, 0);

        for(int i = 0; i<n; i++){
            vector<long long> currCnt(k, 0);

            int currEleRem = nums[i]%k;

            currCnt[currEleRem]++;

            for(int oldRem = 0; oldRem<=k-1; oldRem++){
                int newRem = ((long long)oldRem*nums[i]%k)%k;

                currCnt[newRem] += prevCnt[oldRem];
            }

            prevCnt = move(currCnt);

            for(int x = 0; x<=k-1; x++){
                res[x]+=prevCnt[x];
            }
        }

        return res;
    }
};