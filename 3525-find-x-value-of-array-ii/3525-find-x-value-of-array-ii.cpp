class Solution {
public:

    struct Node {
        int prod;
        long long cnt[5];

        Node() {
            prod = 1;

            for (int i = 0; i < 5; i++) {
                cnt[i] = 0;
            }
        }
    };

    int k;
    vector<Node> tree;
    vector<int> nums;

    Node merge(Node a, Node b) {
        Node res;

        // Product of the complete segment
        res.prod = (a.prod * b.prod) % k;

        // Prefixes completely inside left segment
        for (int r = 0; r < k; r++) {
            res.cnt[r] += a.cnt[r];
        }

        // Prefixes which contain all of left
        // and some prefix of right
        for (int r = 0; r < k; r++) {
            if (b.cnt[r] == 0)
                continue;

            int newR = (a.prod * r) % k;

            res.cnt[newR] += b.cnt[r];
        }

        return res;
    }

    void build(int node, int l, int r) {
        if (l == r) {
            int x = nums[l] % k;

            tree[node].prod = x;
            tree[node].cnt[x] = 1;

            return;
        }

        int mid = (l + r) / 2;

        build(2 * node, l, mid);
        build(2 * node + 1, mid + 1, r);

        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    void update(int node, int l, int r, int idx, int value) {
        if (l == r) {
            int x = value % k;

            tree[node] = Node();

            tree[node].prod = x;
            tree[node].cnt[x] = 1;

            return;
        }

        int mid = (l + r) / 2;

        if (idx <= mid) {
            update(2 * node, l, mid, idx, value);
        } else {
            update(2 * node + 1, mid + 1, r, idx, value);
        }

        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    Node query(int node, int l, int r, int ql, int qr) {
        // Completely inside
        if (ql <= l && r <= qr) {
            return tree[node];
        }

        int mid = (l + r) / 2;

        // Completely in right
        if (ql > mid) {
            return query(2 * node + 1, mid + 1, r, ql, qr);
        }

        // Completely in left
        if (qr <= mid) {
            return query(2 * node, l, mid, ql, qr);
        }

        // Overlaps both
        Node left = query(2 * node, l, mid, ql, qr);
        Node right = query(2 * node + 1, mid + 1, r, ql, qr);

        return merge(left, right);
    }

    vector<int> resultArray(vector<int>& numsInput,
                            int kInput,
                            vector<vector<int>>& queries) {

        nums = numsInput;
        k = kInput;

        int n = nums.size();

        tree.resize(4 * n);

        build(1, 0, n - 1);

        vector<int> ans;

        for (auto &q : queries) {

            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            // Permanent update
            nums[index] = value;
            update(1, 0, n - 1, index, value);

            // We need prefixes of [start ... n-1]
            Node res = query(1, 0, n - 1, start, n - 1);

            ans.push_back(res.cnt[x]);
        }

        return ans;
    }
};