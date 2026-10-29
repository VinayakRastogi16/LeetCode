
class Solution {
    struct Fenwick {
        int n;
        vector<int> bit;

        Fenwick(int n) : n(n), bit(n + 2, 0) {}

        void update(int i, int val) {
            for (; i <= n; i += i & -i) {
                bit[i] ^= val;
            }
        }

        void rangeXor(int l, int r, int val) {
            update(l, val);
            update(r + 1, val);
        }

        int query(int i) {
            int ans = 0;
            for (; i > 0; i -= i & -i) {
                ans ^= bit[i];
            }
            return ans;
        }
    };

public:
    vector<bool> palindromePath(
        int n,
        vector<vector<int>>& edges,
        string s,
        vector<string>& queries
    ) {
        vector<vector<int>> adj(n);

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int LOG = 1;
        while ((1 << LOG) <= n) LOG++;

        vector<vector<int>> up(LOG, vector<int>(n, 0));
        vector<int> depth(n, 0);
        vector<int> tin(n), tout(n);
        vector<int> parent(n, 0);
        vector<int> basePrefix(n, 0);

        int timer = 0;

        // Iterative DFS: avoids recursion stack overflow.
        // State 0 = enter node, state 1 = exit node.
        vector<array<int, 3>> st;
        st.push_back({0, 0, 0});

        while (!st.empty()) {
            auto [u, p, state] = st.back();
            st.pop_back();

            if (state == 0) {
                parent[u] = p;
                up[0][u] = p;

                basePrefix[u] =
                    basePrefix[p] ^ (1 << (s[u] - 'a'));

                tin[u] = ++timer;

                st.push_back({u, p, 1});

                for (int i = (int)adj[u].size() - 1;
                     i >= 0; i--) {
                    int v = adj[u][i];

                    if (v == p) continue;

                    depth[v] = depth[u] + 1;
                    st.push_back({v, u, 0});
                }
            } else {
                tout[u] = timer;
            }
        }

        // Build binary lifting table.
        for (int k = 1; k < LOG; k++) {
            for (int u = 0; u < n; u++) {
                up[k][u] = up[k - 1][up[k - 1][u]];
            }
        }

        auto lca = [&](int u, int v) {
            if (depth[u] < depth[v]) swap(u, v);

            int diff = depth[u] - depth[v];

            for (int k = 0; k < LOG; k++) {
                if (diff & (1 << k)) {
                    u = up[k][u];
                }
            }

            if (u == v) return u;

            for (int k = LOG - 1; k >= 0; k--) {
                if (up[k][u] != up[k][v]) {
                    u = up[k][u];
                    v = up[k][v];
                }
            }

            return up[0][u];
        };

        Fenwick fw(n + 1);
        vector<bool> ans;

        for (const string& q : queries) {
            string op;
            int u, v;
            char c;

            stringstream ss(q);
            ss >> op >> u;

            if (op == "update") {
                ss >> c;

                int oldMask = 1 << (s[u] - 'a');
                int newMask = 1 << (c - 'a');
                int delta = oldMask ^ newMask;

                if (delta != 0) {
                    fw.rangeXor(tin[u], tout[u], delta);
                    s[u] = c;
                }
            } else {
                ss >> v;

                int w = lca(u, v);

                int pu = basePrefix[u] ^ fw.query(tin[u]);
                int pv = basePrefix[v] ^ fw.query(tin[v]);

                int mask = pu ^ pv ^ (1 << (s[w] - 'a'));

                // At most one set bit.
                ans.push_back((mask & (mask - 1)) == 0);
            }
        }

        return ans;
    }
};
