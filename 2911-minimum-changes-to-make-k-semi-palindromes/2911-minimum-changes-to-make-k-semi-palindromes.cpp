class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();

        // cost[l][r] = minimum changes to make s[l..r]
        // a semi-palindrome
        vector<vector<int>> cost(n, vector<int>(n, 1e9));

        // Calculate cost for every substring
        for (int l = 0; l < n; l++) {
            for (int r = l + 1; r < n; r++) {

                int len = r - l + 1;

                // Try every proper divisor d of len
                for (int d = 1; d < len; d++) {

                    if (len % d != 0)
                        continue;

                    int changes = 0;

                    // There are d groups
                    for (int start = 0; start < d; start++) {

                        int left = start;
                        int right = len - d + start;

                        // Move inside this group
                        while (left < right) {

                            if (s[l + left] != s[l + right])
                                changes++;

                            left += d;
                            right -= d;
                        }
                    }

                    cost[l][r] = min(cost[l][r], changes);
                }
            }
        }

        // dp[i][j]:
        // first i characters divided into j parts
        vector<vector<int>> dp(
            n + 1,
            vector<int>(k + 1, 1e9)
        );

        dp[0][0] = 0;

        for (int i = 1; i <= n; i++) {

            for (int parts = 1; parts <= k; parts++) {

                // Last part starts at p
                for (int p = 0; p < i; p++) {

                    int len = i - p;

                    // A part of length 1 is invalid
                    if (len < 2)
                        continue;

                    if (dp[p][parts - 1] == 1e9)
                        continue;

                    dp[i][parts] = min(
                        dp[i][parts],
                        dp[p][parts - 1] + cost[p][i - 1]
                    );
                }
            }
        }

        return dp[n][k];
    }
};