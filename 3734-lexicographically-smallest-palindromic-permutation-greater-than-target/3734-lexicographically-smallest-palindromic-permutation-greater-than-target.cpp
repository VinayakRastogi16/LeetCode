class Solution {
public:
    int midChar = '$';
    int halfLen = 0;
    string result ="";
    bool solve(string& curr, vector<int>& cnt, string t, int i, bool greater){
        if(curr.length()==halfLen){
            string candidate = curr;
            string rH = curr;
            reverse(begin(rH), end(rH));

            if(midChar!='$'){
                candidate+=midChar;
            }

            candidate+=rH;

            if(candidate>t){
                result = candidate;
                return true;
            }

            return false;
        }

        for(char ch = 'a'; ch<='z'; ch++){
            if(cnt[ch-'a']==0) continue;

            if(!greater&&ch<t[i])continue;

            curr.push_back(ch);
            cnt[ch-'a']--;

            bool isgreater = greater || ch>t[i];

            if(solve(curr, cnt, t, i+1, isgreater)){
                return true;
            }

            curr.pop_back();
            cnt[ch-'a']++;

        }

        return false;
    }

    string lexPalindromicPermutation(string s, string target) {
        int n = s.length();

        vector<int> cnt(26, 0);
        for(char& ch:s)
            cnt[ch-'a']++;

        int oddcnt = 0;
        for(int i = 0; i<26;i++){
            if(cnt[i]%2==1){
                oddcnt++;
                midChar = i+'a';
            }
        }

        if(oddcnt>1) return "";

        for(int c = 0; c<26;c++){
            cnt[c]/=2;
        }
        
        halfLen = n/2;

        string curr;
        solve(curr, cnt, target, 0, false);

        return result;

    }
};