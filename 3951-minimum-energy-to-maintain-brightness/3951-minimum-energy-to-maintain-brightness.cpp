class Solution {
public:
    long long minEnergy(int n, int brightness, vector<vector<int>>& gap) {
        sort(gap.begin(), gap.end());

        long long activeTime = 0;

        long long l = gap[0][0];
        long long r = gap[0][1];

        for(int i = 1; i < gap.size(); i++){
            long long s = gap[i][0];
            long long e = gap[i][1];

            if(s<=r+1){
                r = max(r,e);
                
            }else{
                activeTime += r-l+1;
                l = s;
                r = e;
            }
            
            
        }

        activeTime += r-l+1;
        long long bulbNeeded = (brightness+2)/3;

        return bulbNeeded * activeTime;
    }
};