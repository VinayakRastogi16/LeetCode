class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> mini(n, 0);
        int maxi= INT_MIN;
        mini[n-1] = nums[n-1];

        for(int i = n-2; i>=0;i--){
            mini[i] = min(mini[i+1], nums[i]);
        }

        for(int j = 0; j<n; j++){
            maxi = max(maxi, nums[j]);
            int temp = maxi-mini[j];
            if(temp<=k){
                return j;
            } 
        }
        return -1;
    }
};