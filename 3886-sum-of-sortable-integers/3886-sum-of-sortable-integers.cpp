class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        for (int k = 1; k <= n; k++) {
            if (n % k) continue;
            bool ok = true;
            int prevMax = 0;
            for (int s = 0; s < n && ok; s += k) {
                int desc = 0, mn = INT_MAX, mx = 0;
                for (int i = s; i < s + k; i++) {
                    int nxt = (i + 1 < s + k) ? nums[i + 1] : nums[s];
                    if (nums[i] > nxt) desc++;
                    mn = min(mn, nums[i]);
                    mx = max(mx, nums[i]);
                }
                if (desc > 1 || mn < prevMax) ok = false;
                prevMax = mx;
            }
            if (ok) ans += k;
        }
        return (int)ans;
    }
};