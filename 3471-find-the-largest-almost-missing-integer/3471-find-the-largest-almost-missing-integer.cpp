class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int l = nums.size();
        int i, j;

        for(i = 0; i <= l-k; i++) {
            for(j = i; j < i+k; j++) {
                
                bool found = false;

                for(int p = i; p < j; p++) {
                    if(nums[p] == nums[j]) {
                        found = true;
                        break;
                    }
                }

                if(!found)
                    m[nums[j]]++;
            }
        }

        vector<int> a;

        for(auto it = m.begin(); it != m.end(); it++) {
            if(it->second == 1) {
                a.push_back(it->first);
            }
        }

        if(a.empty())
            return -1;

        sort(a.begin(), a.end());

        return a[a.size()-1];
    }
};