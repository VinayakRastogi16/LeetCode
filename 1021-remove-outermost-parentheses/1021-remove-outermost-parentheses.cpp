class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.size();
        int opCnt = 0;
        string ans = "";
        stack<char> st;

        for(int i = 0; i<n; i++){
            if(s[i]=='('){
                st.push(s[i]);
                if(st.size()>1 && !st.empty()){
                    ans+=st.top();
                }
            }else{
                st.pop();
                if(st.size()>=1 && !st.empty()){
                    ans+=s[i];
                }else{
                    continue;
                }
            }
        }

        return ans;
    }
};