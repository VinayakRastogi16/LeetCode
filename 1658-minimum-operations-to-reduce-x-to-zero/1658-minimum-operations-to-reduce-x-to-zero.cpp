class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int tot = 0;
        for(int i : nums)
            tot+=i;
        
        int t = tot-x;

        if(t<0)return -1;

        if(t==0)return n;

        int l = 0;
        int sum = 0;
        int maxLen = -1;

        for(int r = 0; r<n; r++){
            sum+=nums[r];

            while(sum>t && l<=r){
                sum-=nums[l];
                l++;
            }

            if(sum==t){
                maxLen = max(maxLen, r-l+1);
            }
        }

        if(maxLen == -1)return -1;

        return n-maxLen;

    }
};