class Solution {
public:
    string shortestBeautifulSubstring(string s, int k){
        int n = s.length();

        for(int len = k; len<=n; len++){
            string r = "";
            for(int st = 0; st<=n-len; st++){
                string temp = s.substr(st, len);

                int ones = 0;
                for(char& ch:temp){
                    ones += (ch=='1')?1:0;

                }

                if(ones==k){
                    if(r.empty()||temp<r){
                        r = temp;
                    }
                }
            }

            if(!r.empty()){
                return r;
            }
        }
        return "";
    }
};