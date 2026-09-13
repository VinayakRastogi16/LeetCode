class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        int ans = 0;

        map<pair<int, int>, int> mp;

        for(int r1 = 0; r1<n; r1++){
            for(int c1 = 0; c1<n; c1++){
                if(img1[r1][c1]==0)
                    continue;
                
                for(int r2 = 0; r2<n; r2++){
                    for(int c2 = 0; c2<n; c2++){
                        if(img2[r2][c2]==0)
                            continue;

                        int dr = r2-r1;
                        int dc = c2-c1;

                        mp[{dr, dc}]++;

                        ans = max(ans, mp[{dr, dc}]);

                    }
                }
            }
        }

        return ans;
    }
};