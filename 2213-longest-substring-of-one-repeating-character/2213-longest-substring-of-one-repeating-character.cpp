class Solution {
public:
    struct Node {
        int pre, suf, best;
        char leftCh, rightCh;
    };

    vector<Node> tree;
    string s;
    int n;

    Node merge(const Node& L, const Node& R) {
        Node res;
        res.leftCh = L.leftCh;
        res.rightCh = R.rightCh;

        res.pre = L.pre;
        if (L.pre == (int)L.suf + 0 && false) {} // placeholder, not used

        // pre: if entire left side is one char equal to right's left char... 
        // handled generally below using segment lengths implicitly via pre/suf only
        res.pre = L.pre;
        res.suf = R.suf;

        // Extend pre across the boundary if left segment is fully uniform
        // We need segment length info; store it via pre/suf and best trick:
        res.best = max(L.best, R.best);

        if (L.rightCh == R.leftCh) {
            int merged = L.suf + R.pre;
            res.best = max(res.best, merged);
        }

        return res;
    }

    // We actually need lengths to know if L.pre spans the whole segment.
    // So better to carry segment length in build/query via node range, not stored.

    void build(int node, int start, int end) {
        if (start == end) {
            tree[node] = { 1, 1, 1, s[start], s[start] };
            return;
        }
        int mid = (start + end) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        pull(node, start, mid, end);
    }

    void pull(int node, int start, int mid, int end) {
        Node &L = tree[2 * node], &R = tree[2 * node + 1];
        Node res;
        res.leftCh = L.leftCh;
        res.rightCh = R.rightCh;

        int leftLen = mid - start + 1;
        int rightLen = end - mid;

        res.pre = L.pre;
        if (L.pre == leftLen && L.rightCh == R.leftCh) {
            res.pre += R.pre;
        }

        res.suf = R.suf;
        if (R.suf == rightLen && R.leftCh == L.rightCh) {
            res.suf += L.suf;
        }

        res.best = max(L.best, R.best);
        if (L.rightCh == R.leftCh) {
            res.best = max(res.best, L.suf + R.pre);
        }

        tree[node] = res;
    }

    void update(int node, int start, int end, int idx, char ch) {
        if (start == end) {
            tree[node] = { 1, 1, 1, ch, ch };
            return;
        }
        int mid = (start + end) / 2;
        if (idx <= mid) update(2 * node, start, mid, idx, ch);
        else update(2 * node + 1, mid + 1, end, idx, ch);
        pull(node, start, mid, end);
    }

    vector<int> longestRepeating(string s_, string queryCharacters, vector<int>& queryIndices) {
        s = s_;
        n = s.size();
        tree.assign(4 * n, Node());
        build(1, 0, n - 1);

        int q = queryIndices.size();
        vector<int> ans(q);

        for (int i = 0; i < q; i++) {
            update(1, 0, n - 1, queryIndices[i], queryCharacters[i]);
            ans[i] = tree[1].best;
        }

        return ans;
    }
};