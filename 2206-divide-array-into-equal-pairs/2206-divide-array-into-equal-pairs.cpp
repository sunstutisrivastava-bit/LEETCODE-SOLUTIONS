class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int l= nums.size();
        int i,j,c=0;
        unordered_map<int,int> mp;
        for(i=0;i<l;i++){
            mp[nums[i]]++;
        }
       for (const auto& [key, value] : mp) {
        if(value%2!=0){
            c++;
            return false;
        }
       }
        return true;
    }
};