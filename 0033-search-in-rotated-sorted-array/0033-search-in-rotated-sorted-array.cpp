class Solution {
public:
    int search(vector<int>& nums, int target) {
        return search(nums, 0, nums.size() - 1, target);
    }

    int search(vector<int> nums, int si, int ei, int target) {
        if (si > ei) return -1;

        int mid = si + (ei - si) / 2;

        if (nums[mid] == target) {
            return mid;
        }

        if (nums[si] <= nums[mid]) {
            if (nums[si] <= target && target <= nums[mid]) {
                return search(nums, si, mid - 1, target);
            } else {
                return search(nums, mid + 1, ei, target);
            }
        } else {
            if (nums[mid] <= target && target <= nums[ei]) {
                return search(nums, mid + 1, ei, target);
            } else {
                return search(nums, si, mid - 1, target);
            }
        }
    }
};
