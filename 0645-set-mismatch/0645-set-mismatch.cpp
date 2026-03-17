class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
    int n = nums.size();
    vector<int> freq(n + 1, 0);
    vector<int> ans(2);

    for (int x : nums)
        freq[x]++;

    for (int i = 1; i <= n; i++) {
        if (freq[i] == 2) ans[0] = i; // repeated
        if (freq[i] == 0) ans[1] = i; // missing
    }

    return ans;
    }
};