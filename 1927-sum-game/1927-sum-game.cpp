class Solution {
public:
    bool sumGame(string num) {
        int n = num.length();
        int lks = 0;
        int rks=  0;

        int lqm = 0;
        int rqm = 0;

        for(int i = 0; i<n; i++){
            if(num[i]=='?'){
                if(i<n/2){
                    lqm++;
                }else{
                    rqm++;
                }
            }else{
                if(i<n/2){
                    lks+=num[i]-'0';
                }else{
                    rks+=num[i]-'0';
                }
            }
        }

        int tqm = lqm+rqm;
        if(tqm%2==1){
            return true;
        }

        int left = 2*lks+9*lqm;
        int right = 2*rks+9*rqm;

        if(right == left){
            return false;
        }

        return true;
    }
};