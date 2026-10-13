
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        vector<long long> v;

        for (int x : nums) {
            v.push_back(1LL * x * x);
        }

        sort(v.begin(), v.end());

        long long ans = 0;
        int n = v.size();

        for (int i = 0; i < n; i++) {
            if (i < n / 2) {
                ans -= v[i];
            } else {
                ans += v[i];
            }
        }

        return ans;
    }
};
