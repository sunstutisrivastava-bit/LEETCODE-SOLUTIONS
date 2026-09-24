class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int i,j,l=nums.size(),c=-1;
        for(i=0;i<l;i++){
            if(nums[i]>=i){
                int s=0;
                while(nums[i]>0){
                    s=s+nums[i]%10;
                    nums[i]=nums[i]/10;
                }
                if(i==s){
                    c=i;
                    break;
                }
            }
        }
        return c;
    }
};