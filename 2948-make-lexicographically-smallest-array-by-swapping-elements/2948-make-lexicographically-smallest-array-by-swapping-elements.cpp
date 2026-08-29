class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        
        int n = nums.size();

        // value, original index
        vector<pair<int,int>> v;

        for (int i = 0; i < n; i++) {
            v.push_back({nums[i], i});
        }

        sort(v.begin(), v.end());

        int i = 0;

        while (i < n) {

            int j = i;

            // Find all values that can be connected
            while (j + 1 < n &&
                   v[j + 1].first - v[j].first <= limit) {
                j++;
            }

            // Original indices of this group
            vector<int> ind;

            for (int k = i; k <= j; k++) {
                ind.push_back(v[k].second);
            }

            // Smallest index gets smallest value
            sort(ind.begin(), ind.end());

            for (int k = 0; k < ind.size(); k++) {
                nums[ind[k]] = v[i + k].first;
            }

            i = j + 1;
        }

        return nums;
    }
};