class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int l= nums.size();
        vector<int> b(2);
       int i,j,n;
       unordered_map<int,int>mp;
       for(i=0;i<l;i++){
        n=target-nums[i];
        if(mp.find(n)!=mp.end()){
        return{mp[n],i};
        }
        mp[nums[i]]=i;
    }
    return{};
    }
};