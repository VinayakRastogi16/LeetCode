class Solution {
public:
    int maxProduct(int n) {
        int mx1 = 0, mx2 = 0;
        while(n>0){
            int dig = n%10;
            
            if(dig>=mx1){
                mx2 = mx1; 
                mx1 = dig;
            }else if(dig>mx2){
                mx2 = dig;
            }

            n/=10;
        }

        return mx1*mx2;
    }
};