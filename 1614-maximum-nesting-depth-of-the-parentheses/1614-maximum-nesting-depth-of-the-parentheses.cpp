class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;
        int cnt = 0;
        if(s.length()<2)return 0;
        for(int i = 0; i<s.length(); i++){
            
            if(s[i]=='('){
                cnt++;
                ans = max(ans, cnt);
            }else if(s[i]==')'){
                cnt--;
            }else{
                continue;
            }
        }
        return ans;
    }
};