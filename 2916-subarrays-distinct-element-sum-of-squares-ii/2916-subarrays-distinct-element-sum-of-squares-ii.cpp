class Solution {
public:
    const long long MOD = 1e9 + 7;

    struct Node {
        long long sum = 0;
        long long sq = 0;
        long long lazy = 0;
    };

    vector<Node> seg;

    void apply(int idx, int l, int r, long long val) {
        long long len = r - l + 1;

        long long s = seg[idx].sum;

        seg[idx].sq = (seg[idx].sq +
                       2 * val % MOD * s % MOD +
                       len * val % MOD * val % MOD) % MOD;

        seg[idx].sum = (s + len * val) % MOD;

        seg[idx].lazy = (seg[idx].lazy + val) % MOD;
    }

    void push(int idx, int l, int r) {
        if (seg[idx].lazy == 0)
            return;

        int mid = (l + r) / 2;

        apply(idx * 2, l, mid, seg[idx].lazy);
        apply(idx * 2 + 1, mid + 1, r, seg[idx].lazy);

        seg[idx].lazy = 0;
    }

    void update(int idx, int l, int r,
                int ql, int qr, int val) {

        if (ql > r || qr < l)
            return;

        if (ql <= l && r <= qr) {
            apply(idx, l, r, val);
            return;
        }

        push(idx, l, r);

        int mid = (l + r) / 2;

        update(idx * 2, l, mid, ql, qr, val);
        update(idx * 2 + 1, mid + 1, r, ql, qr, val);

        seg[idx].sum = (seg[idx * 2].sum +
                        seg[idx * 2 + 1].sum) % MOD;

        seg[idx].sq = (seg[idx * 2].sq +
                       seg[idx * 2 + 1].sq) % MOD;
    }

    long long query(int idx, int l, int r,
                    int ql, int qr) {

        if (ql > r || qr < l)
            return 0;

        if (ql <= l && r <= qr)
            return seg[idx].sq;

        push(idx, l, r);

        int mid = (l + r) / 2;

        return (query(idx * 2, l, mid, ql, qr) +
                query(idx * 2 + 1, mid + 1, r, ql, qr)) % MOD;
    }

    int sumCounts(vector<int>& nums) {
        int n = nums.size();

        seg.resize(4 * n);

        unordered_map<int, int> last;

        long long ans = 0;

        for (int i = 0; i < n; i++) {

            int p = -1;

            if (last.find(nums[i]) != last.end())
                p = last[nums[i]];

            // Increase distinct counts in range [p+1, i]
            update(1, 0, n - 1, p + 1, i, 1);

            last[nums[i]] = i;

            // Sum of squares for all subarrays ending at i
            ans = (ans + query(1, 0, n - 1, 0, i)) % MOD;
        }

        return ans;
    }
};