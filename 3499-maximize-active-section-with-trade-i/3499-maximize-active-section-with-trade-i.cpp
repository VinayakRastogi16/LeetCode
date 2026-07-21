// class Solution {
// public:
//     int maxActiveSectionsAfterTrade(string s) {
        
//         s = '1'+s+'1';
//         vector<pair<char, int>> grp;

//         for(char ch:s){
//             if(grp.empty()||grp.back().first != ch)
//                 grp.push_back({ch, 1});
//             else
//                 grp.back().second++;
//         }

//         int ones = 0;
//         for(char ch:s){
//             if(ch == '1')ones++;
//         }

//         ones -= 2;

//         int ans = ones;

//         for(int i = 1; i+1<grp.size(); i++){
//             if(grp[i].first == '1'){
//                 int lZero = (grp[i-1].first == '0')? grp[i-1].second:0;
//                 int rZero = (grp[i+1].first == '0')? grp[i+1].second:0;

//                 ans = max(ans, ones+lZero+rZero);
//             }
//         }

//         return ans;
        
//     }
// };


class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        s = "1" + s + "1";

        int totalOnes = -2; // ignore the two added 1's
        int best = 0;

        int prevZero = 0;
        bool seenPrevZero = false;

        int i = 0, n = s.size();

        while (i < n) {
            char ch = s[i];
            int len = 0;

            while (i < n && s[i] == ch) {
                len++;
                i++;
            }

            if (ch == '1') {
                totalOnes += len;
            } else {
                if (seenPrevZero)
                    best = max(best, prevZero + len);

                prevZero = len;
                seenPrevZero = true;
            }
        }

        return totalOnes + best;
    }
};