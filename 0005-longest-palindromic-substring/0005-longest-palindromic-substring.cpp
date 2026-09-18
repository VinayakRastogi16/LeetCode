class Solution {
public:

    // vector<vector<bool>> isPalindrome;
    // int n;
    
    // pair<int, int> solve(string& s, int i, int j){
        
    //     if(i==n) return {0,0};

    //     if(j==n)return solve(s, i+1, i+1);

    //     pair<int, int> ans = {0,0};

    //     if(isPalindrome[i][j]){
    //         ans = {i, j-i+1};
    //     }

    //     pair<int, int> next = solve(s, i, j+1);

    //     if(next.second>ans.second){
    //         ans = next;
    //     }

    //     return ans;
    // }

    // string longestPalindrome(string s) {
    //     n = s.length();
    //     isPalindrome.assign(n, vector<bool>(n, false));

    //     int len = 1;

    //     while(len<=n){
    //         int i = 0;
    //         while(i+len-1<n){
    //             int j = i+len-1;
    //             if(len == 1){
    //                 isPalindrome[i][j] = true;
    //             }else if(len == 2){
    //                 isPalindrome[i][j] = s[i]==s[j];
    //             }else{
    //                 isPalindrome[i][j] = (s[i]==s[j]&&isPalindrome[i+1][j-1]);
    //             }

    //             i++;
    //         }
    //         len++; 
    //     }
        
    //     auto ans = solve(s, 0, 0);

    //     return s.substr(ans.first, ans.second);
    // }

    string longestPalindrome(string s) {
        string t = "^";

        for(char c : s){
            t+= "#";
            t+= c;
        }

        t += "#$";

        int n = t.size();

        vector<int> P(n, 0);

        int center = 0;
        int r = 0;

        int maxLen = 0;
        int cenIdx = 0;

        for(int i = 1; i<n-1; i++){
            int mir = 2*center-i;

            if(i<r){
                P[i] = min(r-i, P[mir]);
            }

            while(t[i+(1+P[i])]==t[i-(1+P[i])]){
                P[i]++;
            }

            if(i+P[i]>r){
                center = i;
                r = P[i]+i;

            }

            if(P[i]>maxLen){
                maxLen = P[i];
                cenIdx = i;
            }
        }
        int st = (cenIdx - maxLen)/2;
        return s.substr(st, maxLen);
    }
};