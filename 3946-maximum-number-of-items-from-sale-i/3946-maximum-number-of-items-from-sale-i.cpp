class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        // free[i] = number of different item types
        // that item i gives for free
        vector<int> free(n, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && items[j][0] % items[i][0] == 0) {
                    free[i]++;
                }
            }
        }

        // dp[b] = maximum number of items
        // obtainable with budget b
        vector<int> dp(budget + 1, 0);

        for (int i = 0; i < n; i++) {
            int price = items[i][1];

            // First copy is special:
            // 1 purchased + free[i] free copies
            vector<int> ndp = dp;

            for (int b = price; b <= budget; b++) {
                ndp[b] = max(
                    ndp[b],
                    dp[b - price] + 1 + free[i]
                );
            }

            // Additional copies:
            // each costs price and gives only 1 item
            for (int b = price; b <= budget; b++) {
                ndp[b] = max(
                    ndp[b],
                    ndp[b - price] + 1
                );
            }

            dp = ndp;
        }

        return dp[budget];
    }
};