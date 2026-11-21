class Solution {
public:

    vector<int> newParent;
    vector<int> last;
    vector<vector<int>> tree;

    void findParents(int u, vector<int>& parent, string& s) {

        int c = s[u] - 'a';

        // Nearest same-character ancestor
        int old = last[c];

        if (u == 0) {
            newParent[u] = -1;
        }
        else if (old != -1) {
            newParent[u] = old;
        }
        else {
            newParent[u] = parent[u];
        }

        // Current node is now the nearest
        // same-character node for its descendants
        last[c] = u;

        for (int v : tree[u]) {
            findParents(v, parent, s);
        }

        // Restore previous ancestor
        last[c] = old;
    }

    int getSize(int u, vector<vector<int>>& newTree,
                vector<int>& ans) {

        int size = 1;

        for (int v : newTree[u]) {
            size += getSize(v, newTree, ans);
        }

        ans[u] = size;

        return size;
    }

    vector<int> findSubtreeSizes(vector<int>& parent, string s) {

        int n = parent.size();

        tree.assign(n, {});
        newParent.assign(n, -1);
        last.assign(26, -1);

        // Build original tree
        for (int i = 1; i < n; i++) {
            tree[parent[i]].push_back(i);
        }

        // Step 1:
        // Calculate every node's new parent
        findParents(0, parent, s);

        // Step 2:
        // Build final tree
        vector<vector<int>> newTree(n);

        for (int i = 1; i < n; i++) {
            newTree[newParent[i]].push_back(i);
        }

        // Step 3:
        // Calculate subtree sizes
        vector<int> ans(n);

        getSize(0, newTree, ans);

        return ans;
    }
};