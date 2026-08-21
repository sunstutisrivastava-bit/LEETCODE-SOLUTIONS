class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();

        long long low = 1;
        long long high = 1LL * (*min_element(coins.begin(), coins.end())) * k;

        while (low < high) {
            long long mid = low + (high - low) / 2;

            long long cnt = 0;

            for (int mask = 1; mask < (1 << n); mask++) {
                long long lcm = 1;
                int bits = 0;
                bool ok = true;

                for (int i = 0; i < n; i++) {
                    if (mask & (1 << i)) {
                        bits++;

                        long long g = gcd(lcm, (long long)coins[i]);
                        lcm = lcm / g * coins[i];

                        if (lcm > mid) {
                            ok = false;
                            break;
                        }
                    }
                }

                if (!ok)
                    continue;

                if (bits % 2)
                    cnt += mid / lcm;
                else
                    cnt -= mid / lcm;
            }

            if (cnt >= k)
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};