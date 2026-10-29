
class Solution {
public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges,
                                string s, vector<string>& queries) {
        vector<vector<int>> adj(n);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int LOG = 1;
        while ((1 << LOG) <= n) LOG++;

        vector<vector<int>> up(LOG, vector<int>(n));
        vector<int> parent(n), depth(n), tin(n), tout(n);
        vector<int> order, sz(n, 1), pref(n);

        // Initial character masks
        vector<int> mask(n);
        for (int i = 0; i < n; i++)
            mask[i] = 1 << (s[i] - 'a');

        // Iterative DFS: Euler order and initial root-prefix XOR
        vector<int> st = {0};
        parent[0] = 0;
        pref[0] = mask[0];

        while (!st.empty()) {
            int u = st.back();
            st.pop_back();

            tin[u] = order.size();
            order.push_back(u);

            for (int v : adj[u]) {
                if (v == parent[u]) continue;

                parent[v] = u;
                depth[v] = depth[u] + 1;
                pref[v] = pref[u] ^ mask[v];
                st.push_back(v);
            }
        }

        // Subtree sizes and Euler exit positions
        for (int i = n - 1; i > 0; i--) {
            int u = order[i];
            sz[parent[u]] += sz[u];
        }

        for (int u = 0; u < n; u++)
            tout[u] = tin[u] + sz[u] - 1;

        for (int u = 0; u < n; u++)
            up[0][u] = parent[u];

        for (int j = 1; j < LOG; j++) {
            for (int u = 0; u < n; u++)
                up[j][u] = up[j - 1][up[j - 1][u]];
        }

        auto lca = [&](int u, int v) {
            if (depth[u] < depth[v]) swap(u, v);

            int diff = depth[u] - depth[v];

            for (int j = 0; j < LOG; j++) {
                if (diff & (1 << j))
                    u = up[j][u];
            }

            if (u == v) return u;

            for (int j = LOG - 1; j >= 0; j--) {
                if (up[j][u] != up[j][v]) {
                    u = up[j][u];
                    v = up[j][v];
                }
            }

            return parent[u];
        };

        // Fenwick tree for range XOR updates and point queries
        vector<int> bit(n + 1, 0);

        auto add = [&](int pos, int val) {
            for (int i = pos + 1; i <= n; i += i & -i)
                bit[i] ^= val;
        };

        auto pointQuery = [&](int pos) {
            int res = 0;

            for (int i = pos + 1; i > 0; i -= i & -i)
                res ^= bit[i];

            return res;
        };

        auto rangeUpdate = [&](int l, int r, int val) {
            add(l, val);

            if (r + 1 < n)
                add(r + 1, val);
        };

        vector<bool> ans;

        for (string &q : queries) {
            string type;
            int u;

            stringstream ss(q);
            ss >> type >> u;

            if (type == "update") {
                char c;
                ss >> c;

                int newMask = 1 << (c - 'a');
                int delta = mask[u] ^ newMask;

                rangeUpdate(tin[u], tout[u], delta);

                mask[u] = newMask;
                s[u] = c;
            } else {
                int v;
                ss >> v;

                int w = lca(u, v);

                int pu = pref[u] ^ pointQuery(tin[u]);
                int pv = pref[v] ^ pointQuery(tin[v]);

                int pathMask = pu ^ pv ^ mask[w];

                ans.push_back((pathMask & (pathMask - 1)) == 0);
            }
        }

        return ans;
    }
};
