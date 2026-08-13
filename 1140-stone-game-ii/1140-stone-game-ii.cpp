class Solution {
public:
    int n;
    vector<int> piles;
    vector<vector<int>> dp;
    vector<int> suffix;

    int solve(int i, int M) {
        if (i >= n)
            return 0;

        if (dp[i][M] != -1)
            return dp[i][M];

        int ans = 0;

        for (int X = 1; X <= 2 * M && i + X <= n; X++) {

            int nextM = max(M, X);

            // Total stones from i onwards
            // minus what opponent can get
            int current = suffix[i] - solve(i + X, nextM);

            ans = max(ans, current);
        }

        return dp[i][M] = ans;
    }

    int stoneGameII(vector<int>& piles) {
        this->piles = piles;
        n = piles.size();

        // suffix[i] = total stones from i to n-1
        suffix.resize(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + piles[i];
        }

        dp.assign(n, vector<int>(n + 1, -1));

        return solve(0, 1);
    }
};