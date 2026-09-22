class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k, 0);
        vector<long long> dp(k, 0);

        for (int num : nums) {
            vector<long long> newdp(k, 0);

            // Start a new subarray with only nums[i]
            newdp[num % k]++;

            // Extend all previous subarrays
            for (int r = 0; r < k; r++) {
                int newR = (r * (num % k)) % k;
                newdp[newR] += dp[r];
            }

            dp = newdp;

            // Every subarray ending here is one valid operation
            for (int r = 0; r < k; r++) {
                ans[r] += dp[r];
            }
        }

        return ans;
    }
};