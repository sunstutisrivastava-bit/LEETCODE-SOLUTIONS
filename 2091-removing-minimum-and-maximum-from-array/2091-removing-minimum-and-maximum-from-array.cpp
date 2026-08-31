class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int l = nums.size();

        int i, a, b, m, n;
        m = n = nums[0];
        a = b = 0;

        for(i = 0; i < l; i++) {
            if(nums[i] < m) {
                m = nums[i];
                a = i;
            }

            if(nums[i] > n) {
                n = nums[i];
                b = i;
            }
        }

        if(a == b) {
            return 1;
        }

        int left = min(a, b);
        int right = max(a, b);

        int p = right + 1;                    // both front
        int q = l - left;                     // both back
        int r = (left + 1) + (l - right);    // front + back

        return min({p, q, r});
    }
};