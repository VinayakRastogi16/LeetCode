 class Solution {
public:
    bool checkString(string s) {
        int cnt_a = count(begin(s), end(s), 'a');

        for(int i = 0; i<cnt_a; i++){
            if(s[i]!='a'){
                return false;
            }
        }
        return true;
    }
};