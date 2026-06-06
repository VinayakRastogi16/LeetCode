class Solution {
public:
    bool consecutiveSetBits(int n) {
        int y = n&(n>>1);
        return y!=0 && (y & (y-1))==0;
    }
};