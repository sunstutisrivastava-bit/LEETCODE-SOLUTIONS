class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int i,j,l,s=nums[0],m,k=0,c=0;
        l=nums.size();
        m=nums[0];
        for(i=1;i<l;i++){
             s= nums[i]>(s+nums[i])?nums[i]:(s+nums[i]);
            m=m>s?m:s;
        }
        return m;
    }
};