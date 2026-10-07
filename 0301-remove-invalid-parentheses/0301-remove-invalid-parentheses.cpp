class Solution {
public:
    int n;
    unordered_set<string> st;

    void solve(string& s, int i, string& curr, int opCnt, int& maxLen) {
        if (opCnt < 0)
            return;

        if (i == n) {
            if (opCnt == 0) {
                if (curr.length() > maxLen) {
                    maxLen = curr.length();
                    st.clear();
                }

                if (curr.length() == maxLen) {
                    st.insert(curr);
                }
            }
            return;
        }

        if (s[i] != '(' && s[i] != ')') {
            curr.push_back(s[i]);
            solve(s, i+1, curr, opCnt, maxLen);
            curr.pop_back();
            return;
        }

        curr.push_back(s[i]);

        solve(s, i+1, curr, opCnt+(s[i]=='('?1:-1), maxLen);

        curr.pop_back();

        solve(s, i+1, curr, opCnt, maxLen);
    }

    vector<string> removeInvalidParentheses(string s) {
        n = s.length();
        st.clear();

        int maxLen = 0;
        string curr = "";

        solve(s, 0, curr, 0, maxLen);

        return vector<string>(begin(st), end(st));
    }
};