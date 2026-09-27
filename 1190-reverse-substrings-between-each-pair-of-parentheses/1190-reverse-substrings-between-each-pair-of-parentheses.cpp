class Solution {
public:
    string reverseParentheses(string s) {
        int i = 0;
        int n = s.length();
        stack<string> st;
        string curr = "";

        for(char c : s){
            if(c == '('){
                st.push(curr);
                curr = "";
            }else if(c==')'){
                reverse(begin(curr), end(curr));
                curr = st.top()+curr;
                st.pop();
            }else{
                curr+=c;
            }
        }

        return curr;
    }
};