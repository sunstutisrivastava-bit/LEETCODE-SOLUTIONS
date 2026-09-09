class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        map<int, int> mp;
        vector<int> a;

        int n = nums.size();

        for (int x : nums) {
            mp[x]++;
        }

        for (int m = n; m >= 1; m--) {
            if (mp.find(m) == mp.end()) {
                a.push_back(m);
            }
        }

        return a;
    }
};