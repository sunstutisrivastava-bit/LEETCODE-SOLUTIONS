class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minOdd = INT_MAX;
        bool hasOdd = false;

        // Find the smallest odd number
        for (int x : nums1) {
            if (x % 2 == 1) {
                hasOdd = true;
                minOdd = min(minOdd, x);
            }
        }

        // All numbers are even
        if (!hasOdd)
            return true;

        // Every even number must be greater than minOdd
        for (int x : nums1) {
            if (x % 2 == 0 && x < minOdd)
                return false;
        }

        return true;
    }
};