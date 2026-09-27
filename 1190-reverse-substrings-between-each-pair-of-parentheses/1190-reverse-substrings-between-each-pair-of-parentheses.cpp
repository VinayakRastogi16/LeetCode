class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> len;
        string curr = "";

        for(char c : s){
            if(c == '('){
                len.push(curr.length());
            }else if(c==')'){
                int l = len.top();
                len.pop();
                reverse(begin(curr)+l, end(curr));
            }else{
                curr.push_back(c);
            }
        }

        return curr;
    }
};