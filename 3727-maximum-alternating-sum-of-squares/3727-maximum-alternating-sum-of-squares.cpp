class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long> sqre;

        for(int i:nums){
            sqre.push_back(i*i);
        }

        sort(begin(sqre), end(sqre));
        int mid = n/2;
        long long ans=0;

        for(int i = 0; i<mid; i++){
            ans-=sqre[i];
        }

        for(int i = mid; i<n; i++){
            ans+=sqre[i];
        }

        return ans;


    }
};