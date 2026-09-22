class Solution {
public:
    struct Node {
        int prod;
        int cnt[5];

        Node() {
            prod = 1;
            memset(cnt, 0, sizeof(cnt));
        }
    };

    int k;
    vector<Node> tree;

    Node merge(Node left, Node right) {

        Node ans;

        // Product of entire segment
        ans.prod = (left.prod * right.prod) % k;

        // Prefixes entirely inside left
        for (int r = 0; r < k; r++) {
            ans.cnt[r] += left.cnt[r];
        }

        // Prefixes that contain all of left
        // and then some prefix of right
        for (int r = 0; r < k; r++) {

            int newRem = (left.prod * r) % k;

            ans.cnt[newRem] += right.cnt[r];
        }

        return ans;
    }

    void build(vector<int>& nums, int node, int l, int r) {

        if (l == r) {

            int val = nums[l] % k;

            tree[node].prod = val;
            tree[node].cnt[val] = 1;

            return;
        }

        int mid = l + (r - l) / 2;

        build(nums, node * 2, l, mid);
        build(nums, node * 2 + 1, mid + 1, r);

        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    void update(int node, int l, int r, int idx, int val) {

        if (l == r) {

            val %= k;

            tree[node] = Node();

            tree[node].prod = val;
            tree[node].cnt[val] = 1;

            return;
        }

        int mid = l + (r - l) / 2;

        if (idx <= mid)
            update(node * 2, l, mid, idx, val);
        else
            update(node * 2 + 1, mid + 1, r, idx, val);

        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    Node query(int node, int l, int r, int ql, int qr) {

        // Completely inside
        if (ql <= l && r <= qr)
            return tree[node];

        int mid = l + (r - l) / 2;

        // Query entirely on right
        if (ql > mid)
            return query(node * 2 + 1, mid + 1, r, ql, qr);

        // Query entirely on left
        if (qr <= mid)
            return query(node * 2, l, mid, ql, qr);

        // Split query
        Node left = query(node * 2, l, mid, ql, qr);

        Node right = query(node * 2 + 1, mid + 1, r, ql, qr);

        return merge(left, right);
    }

    vector<int> resultArray(vector<int>& nums, int k,
                            vector<vector<int>>& queries) {

        this->k = k;

        int n = nums.size();

        tree.resize(4 * n);

        build(nums, 1, 0, n - 1);

        vector<int> ans;

        for (auto& q : queries) {

            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            // Persistent update
            update(1, 0, n - 1, index, value);

            // Query nums[start ... n-1]
            Node res = query(1, 0, n - 1, start, n - 1);

            ans.push_back(res.cnt[x]);
        }

        return ans;
    }
};