class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,vector<vector<int>>& queries) {
        vector<pair<int, int>> nodes;
        nodes.reserve(n);
        for (int index = 0; index < n; ++index) {
            nodes.emplace_back(nums[index], index);
        }
        sort(nodes.begin(), nodes.end());

        int log = 1;
        while ((1 << log) < n) {
            ++log;
        }

        vector<vector<int>> jump(n, vector<int>(log));
        int right = n - 1;
        for (int left = n - 1; left >= 0; --left) {
            while (nodes[right].first - nodes[left].first > maxDiff) {
                --right;
            }

            int node = nodes[left].second;
            jump[node][0] = nodes[right].second;
            for (int bit = 1; bit < log; ++bit) {
                jump[node][bit] = jump[jump[node][bit - 1]][bit - 1];
            }
        }

        vector<int> answer;
        answer.reserve(queries.size());
        for (const vector<int>& query : queries) {
            int from = query[0];
            int to = query[1];
            if (nums[from] > nums[to]) {
                swap(from, to);
            }

            if (from == to) {
                answer.push_back(0);
                continue;
            }
            if (nums[from] == nums[to]) {
                answer.push_back(1);
                continue;
            }

            int distance = 0;
            for (int bit = log - 1; bit >= 0; --bit) {
                if (nums[jump[from][bit]] < nums[to]) {
                    distance += 1 << bit;
                    from = jump[from][bit];
                }
            }

            if (nums[jump[from][0]] < nums[to]) {
                answer.push_back(-1);
            } else {
                answer.push_back(distance + 1);
            }
        }

        return answer;
    }
};