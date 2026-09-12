class Solution {
public:

    struct Node {
        long long score;
        vector<int> ind;
    };

    vector<vector<Node>> dp;
    vector<vector<bool>> vis;

    Node solve(int i, int cnt, vector<vector<int>>& v) {

        // No more intervals OR already selected 4
        if (i == v.size() || cnt == 4)
            return {0, {}};

        if (vis[i][cnt])
            return dp[i][cnt];

        vis[i][cnt] = true;

        // OPTION 1: Don't take current interval
        Node skip = solve(i + 1, cnt, v);

        // OPTION 2: Take current interval
        int l = v[i][0];
        int r = v[i][1];
        int w = v[i][2];
        int originalIndex = v[i][3];

        // Find first interval whose left > current right
        int low = i + 1;
        int high = v.size();

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (v[mid][0] > r)
                high = mid;
            else
                low = mid + 1;
        }

        int next = low;

        Node take = solve(next, cnt + 1, v);

        take.score += w;
        take.ind.push_back(originalIndex);

        // Keep indices sorted for lexicographical comparison
        sort(take.ind.begin(), take.ind.end());

        // Choose better score
        if (take.score > skip.score)
            return dp[i][cnt] = take;

        if (take.score < skip.score)
            return dp[i][cnt] = skip;

        // Same score -> lexicographically smaller
        if (take.ind < skip.ind)
            return dp[i][cnt] = take;

        return dp[i][cnt] = skip;
    }


    vector<int> maximumWeight(vector<vector<int>>& intervals) {

        int n = intervals.size();

        vector<vector<int>> v;

        // Add original index
        for (int i = 0; i < n; i++) {
            v.push_back({
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            });
        }

        // Sort according to LEFT
        sort(v.begin(), v.end(), [](auto &a, auto &b) {
            return a[0] < b[0];
        });

        // Dynamic DP arrays
        dp.resize(n + 1, vector<Node>(5));
        vis.resize(n + 1, vector<bool>(5, false));

        return solve(0, 0, v).ind;
    }
};