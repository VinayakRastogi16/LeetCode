class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,int> freq;
        unordered_map<int,int> first;
        unordered_map<int,int> last;

        int deg = 0;

        for(int i = 0; i<nums.size(); i++){
            if(freq.find(nums[i])==freq.end()){
                first[nums[i]]= i;
            }
            freq[nums[i]]++;
            last[nums[i]] = i;

            deg = max(deg, freq[nums[i]]);
        }

        int ans = INT_MAX;

        for(auto x : freq) {
            if(x.second == deg) {
                ans = min(ans, last[x.first] - first[x.first] + 1);
            }
        }

        return ans;



    }
};