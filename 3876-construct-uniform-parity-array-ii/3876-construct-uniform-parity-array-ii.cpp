class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mini = INT_MAX;
        bool hasOdd = false;
        for(int n : nums1){
            if(n%2!=0){
                hasOdd = true;
                mini = min(mini, n);
            }
        }

        if(!hasOdd){
            return true;
        }

        for(int n: nums1){
            if(n%2==0&&n<mini){
                return false;
            }
        }

        return true;
    }
};