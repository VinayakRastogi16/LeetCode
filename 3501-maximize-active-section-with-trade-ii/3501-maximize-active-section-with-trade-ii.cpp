struct Group { int start, length; };

class SparseTable {
public:
    SparseTable(const vector<int>& nums)
        : n(nums.size()), st(std::bit_width(n) + 1, vector<int>(n + 1)) {
        copy(nums.begin(), nums.end(), st[0].begin());
        for (int i = 1; i <= bit_width(n); ++i)
            for (int j = 0; j + (1 << i) <= (int)n; ++j)
                st[i][j] = max(st[i-1][j], st[i-1][j + (1 << (i-1))]);
    }

    int query(unsigned l, unsigned r) const {
        int i = bit_width(r - l + 1) - 1;
        return max(st[i][l], st[i][r - (1 << i) + 1]);
    }

private:
    unsigned n;
    vector<vector<int>> st;
};

class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.size();
        int ones = count(s.begin(), s.end(), '1');

        // Build zero groups and index mapping
        vector<Group> zg;
        vector<int> zgIdx(n);
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                if (i > 0 && s[i-1] == '0') zg.back().length++;
                else zg.push_back({i, 1});
            }
            zgIdx[i] = (int)zg.size() - 1;
        }

        if (zg.empty()) return vector<int>(queries.size(), ones);

        // Adjacent pair sums
        vector<int> adjSums;
        for (int i = 0; i + 1 < (int)zg.size(); i++)
            adjSums.push_back(zg[i].length + zg[i+1].length);

        SparseTable st(adjSums);

        vector<int> ans;
        for (auto& q : queries) {
            int l = q[0], r = q[1];
            // Partial left overlap
            int left = (s[l] == '0') ? (zg[zgIdx[l]].length - (l - zg[zgIdx[l]].start)) : -1;
            // Partial right overlap
            int right = (s[r] == '0') ? (r - zg[zgIdx[r]].start + 1) : -1;

            int startAdj = zgIdx[l] + 1;
            int endAdj   = (s[r] == '1' ? zgIdx[r] : zgIdx[r] - 1) - 1;

            int best = ones;

            // Both ends in same zero-group
            if (s[l]=='0' && s[r]=='0' && zgIdx[l]+1 == zgIdx[r])
                best = max(best, ones + left + right);
            // Full adjacent pairs inside [l, r]
            else if (startAdj <= endAdj)
                best = max(best, ones + st.query(startAdj, endAdj));

            // Left partial + next full zero-group
            if (s[l]=='0' && zgIdx[l]+1 <= (s[r]=='1' ? zgIdx[r] : zgIdx[r]-1))
                best = max(best, ones + left + zg[zgIdx[l]+1].length);

            // Right partial + previous full zero-group
            if (s[r]=='0' && zgIdx[l] < zgIdx[r]-1)
                best = max(best, ones + right + zg[zgIdx[r]-1].length);

            ans.push_back(best);
        }
        return ans;
    }
};