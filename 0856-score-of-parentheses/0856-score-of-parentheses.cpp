class Solution {
public:
    int scoreOfParentheses(string s) {
        int ans = 0;
        int cnt = 0;

        for(int i = 0;i<s.size(); i++){
            if(s[i]=='('){
                cnt++;
            }else{
                cnt--;

                if(s[i-1]=='('){
                    ans+=pow(2, cnt);
                }

            }
        }

        return ans;
    }
};