class Solution {
public:
    int lastRemaining(int n) {
        int st = 1;
        int gap = 1;
        bool l = true;

        while(n>1){
            if(l || n%2==1){
                st += gap;
            }

            n/=2;
            gap*=2;
            l = !l;
        }

        return st;
    }
};