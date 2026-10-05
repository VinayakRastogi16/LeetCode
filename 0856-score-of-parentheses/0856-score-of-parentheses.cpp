class Solution {
public:

    int solve(string &s, int l, int r){
        if(r-l == 1){
            return 1;
        }
        int balance = 0;

        for(int i = l; i<=r; i++){
            if(s[i]=='('){
                balance++;
            }else{
                balance--;
            }

            if(balance == 0){
                if(i==r){
                    return 2*solve(s, l+1, r-1);
                }

                return solve(s, l, i) + solve(s, i+1, r);
            }
        }

        return 0;
    }

    int scoreOfParentheses(string s) {
        return solve(s, 0, s.size()-1);
    }
};