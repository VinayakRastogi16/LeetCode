class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;

        int n = nums.size();
        sort(nums.begin(), nums.end());
        int longest = 1; 
        int count = 1;
        for(int i =1 ; i<n; i++){
            if(nums[i]==nums[i-1]){
                continue;
            }else if(nums[i]==nums[i-1]+1){
                count++;

            }else{
                longest = max(longest, count);
                count = 1;

            }
        }

        return max(longest, count);
    }
};