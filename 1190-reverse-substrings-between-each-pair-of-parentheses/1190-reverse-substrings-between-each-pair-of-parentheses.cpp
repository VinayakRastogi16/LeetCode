class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();

        stack<int> OBidx;
        vector<int> door(n);

        for(int i = 0; i < n; i++){
            if(s[i]=='('){
                OBidx.push(i);
            }else if(s[i]==')'){
                int j = OBidx.top();
                OBidx.pop();
                door[i] = j;
                door[j] = i;
            }
        }

        string res;
        int flag = 1;
        for(int i = 0; i<n; i+=flag){
            if(s[i]=='('||s[i]==')'){
                i = door[i];
                flag = -flag; //changing the direction
            }else{
                res.push_back(s[i]);
            }
        }

        return res;

    }
};