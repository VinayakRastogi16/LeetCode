class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();

        for(int i=0; i<n; i++){
            nums[i] = abs(nums[i]);
        }

        sort(begin(nums), end(nums));
        int mid = n/2;
        long long ans=0;

        for(int i = 0; i<mid; i++){
            ans-=nums[i]*nums[i];
        }

        for(int i = mid; i<n; i++){
            ans+=nums[i]*nums[i];
        }

        return ans;
    }
};