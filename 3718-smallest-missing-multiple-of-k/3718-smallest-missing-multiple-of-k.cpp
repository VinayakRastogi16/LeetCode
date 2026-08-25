class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> st;

        for(int x: nums){
            st.insert(x);
        }

        int m = k;

        while(st.count(m)){
            m+=k;
        }

        return m;
    }
};