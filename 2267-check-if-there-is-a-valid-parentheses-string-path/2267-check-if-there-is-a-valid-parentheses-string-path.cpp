class Solution {
public:
    int m;
    int n;
    bool t[101][101][201];
    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        if ((m + n - 1) % 2 == 1)
            return false;
        if (grid[0][0] != '(' || grid[m - 1][n - 1] != ')')
            return false;

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                for (int cnt = 0; cnt <= i + j + 1; cnt++) {
                    if (i == m - 1 && j == n - 1) {
                        t[i][j][cnt] = (cnt == 0);
                        continue;
                    }

                    t[i][j][cnt] = false;

                    if (i + 1 < m) {
                        int nxtCnt =
                            (grid[i + 1][j] == '(') ? cnt + 1 : cnt - 1;
                        if (nxtCnt >= 0 && t[i + 1][j][nxtCnt]) {
                            t[i][j][cnt] = true;
                        }
                    }

                    if (j + 1 < n) {
                        int nxtCnt =
                            (grid[i][j + 1] == '(') ? cnt + 1 : cnt - 1;
                        if (nxtCnt >= 0 && t[i][j + 1][nxtCnt]) {
                            t[i][j][cnt] = true;
                        }
                    }
                }
            }
        }

        return t[0][0][1];
    }
};