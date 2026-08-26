class Solution {
public:
    string shortestBeautifulSubstring(string s, int k){
        int n = s.length();

        // for(int len = k; len<=n; len++){
        //     string r = "";
        //     for(int st = 0; st<=n-len; st++){
        //         string temp = s.substr(st, len);

        //         int ones = 0;
        //         for(char& ch:temp){
        //             ones += (ch=='1')?1:0;

        //         }

        //         if(ones==k){
        //             if(r.empty()||temp<r){
        //                 r = temp;
        //             }
        //         }
        //     }

        //     if(!r.empty()){
        //         return r;
        //     }
        // }
        // return "";  ####brute force

        int i = 0;
        int j = 0;
        int cnt = 0;
        string ans = "";

        while(j<n){
            if(s[j]=='1')
            cnt++;

            while(cnt>k||s[i]=='0'){
                if(s[i]=='1')
                    cnt--;
                
                i++;
            }
            
            if(cnt==k){
                string temp = s.substr(i, j-i+1);
                if(ans.empty()||ans.length()>j-i+1||
                (temp.length()==ans.length() && temp<ans)){
                    ans = temp;
                }
            }
            j++;
        }
        return ans;
    }
};