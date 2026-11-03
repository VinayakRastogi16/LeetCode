class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxi = *max_element(nums.begin(), nums.end());

        int moves = 0;

        for(int n:nums){
            moves+=maxi-n;
        }

        return moves;
    }
};