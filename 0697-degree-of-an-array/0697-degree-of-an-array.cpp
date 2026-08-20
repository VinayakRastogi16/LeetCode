class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,vector<int>> mp;
        int deg = 0;

        for(int i = 0; i<nums.size(); i++){
            if(mp.find(nums[i])==mp.end()){
                mp[nums[i]]= {0, i, i};
            }
            mp[nums[i]][0]++;
            mp[nums[i]][2] = i;

            deg = max(deg, mp[nums[i]][0]);
        }

        int ans = INT_MAX;

        for(auto x : mp) {
            if(x.second[0] == deg) {
                ans = min(ans, x.second[2] - x.second[1] + 1);
            }
        }

        return ans;
    }
};