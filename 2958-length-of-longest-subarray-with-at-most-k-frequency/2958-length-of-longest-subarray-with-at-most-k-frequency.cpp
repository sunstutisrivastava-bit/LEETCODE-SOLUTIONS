class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int l=nums.size();
        int i,j=0,p=0;
        int c=0;
        unordered_map<int, int> mp;
        for(i=0; i<l; i++) {
    mp[nums[i]]++;
    c++;

    while(mp[nums[i]] > k) {
        mp[nums[j]]--;
        j++;
        c--;
    }
    p=max(p,c);
}
            cout<<c<<endl;
        return p;
        
    }
};