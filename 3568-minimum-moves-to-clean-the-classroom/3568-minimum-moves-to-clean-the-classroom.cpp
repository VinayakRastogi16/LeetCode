class Solution {
public:
    using VB = vector<bool>;
    using VVB = vector<VB>;
    using VVVB = vector<VVB>;
    using VVVVB = vector<VVVB>;
    vector<vector<int>> directions = {{0,1}, {0,-1}, {1, 0}, {-1, 0}};

    struct State{
        int r;
        int c;
        int energyLeft;
        int collectedMask;
    };

    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        int mE = energy;

        int litterBit[20][20];
        int litterCnt=0;
        int sr = 0;
        int sc= 0;

        for(int r = 0; r<m; r++){
            for(int c = 0; c<n; c++){
                litterBit[r][c] = -1;
                if(classroom[r][c] =='S'){
                    sr = r;
                    sc = c;
                }else if(classroom[r][c] =='L'){
                    litterBit[r][c] = litterCnt; // 0th position
                    litterCnt++;
                }
            }
        }

        int allCollected = (1<<litterCnt)-1; //(2^litterCnt)-1
        if(litterCnt == 0) return 0;

        VVVVB visited(m, VVVB(n, VVB(mE+1, VB(1<<litterCnt, false))));

        queue<State> q;
        q.push({sr, sc, mE, 0});
        visited[sr][sc][mE][0] = true;

        int moves = 0;

        while(!q.empty()){
            int currSize = q.size();

            while(currSize--){
                State curr = q.front();
                q.pop();

                if(curr.collectedMask == allCollected){
                    return moves;
                }
                if(curr.energyLeft == 0){
                    continue;
                }

                for(auto &dir:directions){
                    int nR = curr.r + dir[0];
                    int nC = curr.c + dir[1];

                    if(nR<0||nR>=m||nC<0||nC>=n)
                        continue;

                    char cell = classroom[nR][nC];

                    if(cell == 'X')continue;

                    int nextEnergy = curr.energyLeft -1;
                    int nextMask = curr.collectedMask;

                    if(cell == 'R'){
                        nextEnergy = mE;
                    }else if(cell == 'L'){
                        nextMask |= (1<<litterBit[nR][nC]);
                    }

                    if(!visited[nR][nC][nextEnergy][nextMask]){
                        visited[nR][nC][nextEnergy][nextMask]  = true;
                        q.push({nR, nC, nextEnergy, nextMask});
                    }
                }
            }
            moves++;
        }

        return -1;
    }
};