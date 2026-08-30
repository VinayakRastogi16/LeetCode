class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int minElIdx = min_element(begin(nums), end(nums)) - begin(nums);
        int maxElIdx = max_element(begin(nums), end(nums)) - begin(nums);

        int left = min(maxElIdx, minElIdx);
        int right = max(maxElIdx, minElIdx);

        return min({left+1+n-right, right+1, n-left});
    }
};