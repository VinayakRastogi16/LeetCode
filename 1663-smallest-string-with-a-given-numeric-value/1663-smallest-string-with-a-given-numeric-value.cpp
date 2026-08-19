class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans(n, 'a');

        int remaining = k-n;

        for(int i = n-1;i>=0; i--){
            int add = min(25, remaining);

            ans[i]+=add;
            remaining-=add;
        }

        return ans;
    }
};