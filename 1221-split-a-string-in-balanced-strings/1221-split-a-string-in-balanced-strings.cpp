class Solution {
public:
    int balancedStringSplit(string s) {
        int bf = 0;
        int ans = 0;
        for(char ch: s){
            if(ch == 'L'){
                bf++;
            }else{
                bf--;
            }

            if(bf == 0){
                ans++;
            }

        }

        return ans;
    }
};