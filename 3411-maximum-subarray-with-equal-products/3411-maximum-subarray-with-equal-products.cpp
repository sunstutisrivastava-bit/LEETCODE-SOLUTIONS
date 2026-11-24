class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int product = 1;
            int g = 0;
            int l = 1;

            for (int j = i; j < n; j++) {

                product *= nums[j];

                // Product has already become too large.
                // It can never become equal to gcd * lcm.
                if (product > 25200)
                    break;

                g = gcd(g, nums[j]);

                l = l / gcd(l, nums[j]) * nums[j];

                if (product == g * l) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};