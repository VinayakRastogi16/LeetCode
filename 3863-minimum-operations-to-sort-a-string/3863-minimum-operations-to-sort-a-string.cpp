class Solution {
public:
    int minOperations(string s) {
        int n = s.size();

        bool sorted = true;

        for(int i = 1;i<n; i++){
            if(s[i-1]>s[i]){
                sorted = false;
                break;
            }
        }

        if(sorted)return 0;
        if(n==2)return -1;

        string t = s;

        char mn = *min_element(s.begin(), s.end());
        char mx = *max_element(s.begin(), s.end());

        if(s[0]==mn||s[n-1]==mx)return 1;

        if(s.find(mn)!=n-1||s.rfind(mx)!=0)return 2;

        return 3;

    }
};