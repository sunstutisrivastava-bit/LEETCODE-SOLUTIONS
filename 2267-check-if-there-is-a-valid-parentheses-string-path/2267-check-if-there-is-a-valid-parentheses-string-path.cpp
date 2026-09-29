class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Valid parentheses string ki length even honi chahiye
        if ((m + n - 1) % 2 != 0)
            return false;

        // dp[i][j][balance]
        vector<vector<vector<bool>>> dp(
            m,
            vector<vector<bool>>(n, vector<bool>(m + n, false))
        );

        // Starting cell
        int balance = (grid[0][0] == '(') ? 1 : -1;

        if (balance < 0)
            return false;

        dp[0][0][balance] = true;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (i == 0 && j == 0)
                    continue;

                for (int b = 0; b <= m + n; b++) {

                    if (grid[i][j] == '(')
                        balance = b + 1;
                    else
                        balance = b - 1;

                    if (balance < 0)
                        continue;

                    // From top
                    if (i > 0 && dp[i - 1][j][b])
                        dp[i][j][balance] = true;

                    // From left
                    if (j > 0 && dp[i][j - 1][b])
                        dp[i][j][balance] = true;
                }
            }
        }

        // End par balance 0 hona chahiye
        return dp[m - 1][n - 1][0];
    }
};