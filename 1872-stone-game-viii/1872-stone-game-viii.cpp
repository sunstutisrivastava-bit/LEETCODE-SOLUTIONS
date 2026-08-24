class Solution {
public:
    long long stoneGameVIII(vector<int>& stones) {
        int n = stones.size();

        vector<long long> prefix(n);
        prefix[0] = stones[0];

        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + stones[i];
        }

        // Start with the case where Alice takes all stones.
        long long ans = prefix[n - 1];

        // Try every possible point where the first move can end.
        for (int i = n - 2; i >= 1; i--) {
            ans = max(ans, prefix[i] - ans);
        }

        return ans;
    }
};