class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int cnt[3] = {0};

        for (int x : stones) {
            cnt[x % 3]++;
        }

        int c0 = cnt[0];
        int c1 = cnt[1];
        int c2 = cnt[2];

        // No stones with remainder 1 or 2
        if (c1 == 0 && c2 == 0)
            return false;

        // If number of 0-reminder stones is even
        if (c0 % 2 == 0) {
            return c1 > 0 && c2 > 0;
        }

        // If number of 0-reminder stones is odd
        return abs(c1 - c2) > 2;
    }
};