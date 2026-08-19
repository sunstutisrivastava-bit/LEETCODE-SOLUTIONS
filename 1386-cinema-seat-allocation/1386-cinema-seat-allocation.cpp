class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> m;

        for (int i = 0; i < reservedSeats.size(); i++) {
            int row = reservedSeats[i][0];
            int seat = reservedSeats[i][1];

            if (seat >= 2 && seat <= 5)
                m[row] |= 1;

            if (seat >= 4 && seat <= 7)
                m[row] |= 2;

            if (seat >= 6 && seat <= 9)
                m[row] |= 4;
        }

        int ans = (n - m.size()) * 2;

        for (auto it = m.begin(); it != m.end(); it++) {
            int x = it->second;

            if (x == 0)
                ans += 2;
            else if (x == 7)
                ans += 0;
            else if (x == 3 || x == 6)
                ans += 1;
            else
                ans += 1;
        }

        return ans;
    }
};