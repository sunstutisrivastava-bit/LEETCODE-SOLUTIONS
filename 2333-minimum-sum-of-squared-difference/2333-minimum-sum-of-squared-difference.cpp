class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1,
                               vector<int>& nums2,
                               int k1, int k2) {
        long long k = 1LL * k1 + k2;
        vector<long long> freq(100001, 0);

        int maxi = 0;
        long long total = 0;

        for (int i = 0; i < nums1.size(); i++) {
            int d = abs(nums1[i] - nums2[i]);
            freq[d]++;
            maxi = max(maxi, d);
            total += d;
        }

        if (k >= total) return 0;

        for (int d = maxi; d > 0 && k > 0; d--) {
            if (freq[d] == 0) continue;

            long long count = freq[d];

            if (k >= count) {
                freq[d - 1] += count;
                freq[d] = 0;
                k -= count;
            } else {
                freq[d] -= k;
                freq[d - 1] += k;
                k = 0;
            }
        }

        long long ans = 0;

        for (int d = 1; d <= 100000; d++) {
            ans += 1LL * d * d * freq[d];
        }

        return ans;
    }
};