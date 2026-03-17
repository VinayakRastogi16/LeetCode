class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()){
            return false;
        }

        int freq[26] = {0};

        for(int i=0; i< s.length(); i++){
            freq[s[i]-'a']++;
        }
        for(int i=0; i< t.length(); i++){
            if(freq[t[i]-'a']==0){
                return false;
            }
            freq[t[i]-'a']--;
        }
        return true;
    }
};