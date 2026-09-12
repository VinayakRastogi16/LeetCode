class Solution {
public:

    struct Node{
            long long score = -1;
            vector<int> idxs;
            
        };
    int n;
    vector<int> nextIdx;
    vector<vector<Node>> dp;

    int findNext(vector<vector<int>>& intervals, int r){
        int lo = 0, hi = n-1;
        int res = n;

        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(intervals[mid][0]>r){
                res = mid;
                hi = mid-1;
            }else{
                lo = mid+1;
            }
        }

        return res;
    }

    Node solve(vector<vector<int>> &intervals, int i, int k){
        if(k==0||i>=n)return Node();

        if(dp[i][k].score !=-1)return dp[i][k];

        Node skip = solve(intervals, i+1, k);

        int weight = intervals[i][2];
        int idx = intervals[i][3];
        int j = nextIdx[i];

        Node temp =  solve(intervals, j, k-1);
        Node take; 
        take.score = temp.score+weight;
        take.idxs = temp.idxs;
        take.idxs.push_back(idx);

        sort(begin(take.idxs), end(take.idxs));

        Node result;
        if(skip.score>take.score){
            result = skip;
        }else if(skip.score<take.score){
            result = take;
        }else{
            result = (skip.idxs<take.idxs)?skip:take;
        }

        return dp[i][k] = result;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        n = intervals.size();

        for(int i=0; i<n; i++){
            intervals[i].push_back(i);

        }

        sort(begin(intervals), end(intervals));
        nextIdx.resize(n);

        for(int i = 0; i<n; i++){
            int end = intervals[i][1];
            nextIdx[i] = findNext(intervals, end);//binary search
        }

        int K = 4;
        dp.assign(n+1, vector<Node>(K+1));
        return solve(intervals, 0, K).idxs;
    }
};