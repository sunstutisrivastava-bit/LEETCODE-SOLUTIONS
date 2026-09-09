class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i,j;
        i=0;
        for(j=0;j<nums.size();j++){
            if(nums[j]!=0){
                int t=nums[i];
                nums[i]=nums[j];
                nums[j]=t;
                i++;
            }
        }        
    }
};