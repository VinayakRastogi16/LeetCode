class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.length();

        vector<int> st(26, -1);
        vector<int> end(26,0);
        vector<bool> isValid(26, true);

        vector<string> res;

        for(int i = 0; i<n; i++){
            int idx = s[i]-'a';

            if(st[idx]==-1){
                st[idx] = i;
            }

            end[idx]=i;
        }

        for(int c = 0; c<26; c++){
            if(st[c]==-1)continue;

            for(int i = st[c]; i<=end[c]; i++){
                if(st[s[i]-'a']<st[c]){
                    isValid[c] = false;
                    break;
                }

                end[c] = max(end[c], end[s[i]-'a']);
            }
        }

        int lastTakenSt = INT_MAX;

        for(int i =n-1; i>=0; i--){
            int c = s[i]-'a';

            if(!isValid[c])continue;

            if(i == st[c] && end[c]<lastTakenSt){
                res.push_back(s.substr(i, end[c]-i+1));
                lastTakenSt = i;
            }
        }

        return res;
    }
};