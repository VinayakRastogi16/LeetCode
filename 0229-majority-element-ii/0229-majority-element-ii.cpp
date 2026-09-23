class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        vector<int> ans;
        for(int i: nums){
            mp[i]++;
            if(mp[i]>(n/3) && mp[i]==(n/3)+1)
                ans.push_back(i);
        }
        return ans;
    }
};