class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int l=nums.size();
        int i=0,j,c=0,k=0;
        while(k!=l){
            if(nums[i]==0){
                c++;
                for(j=i;j<l-1;j++){
                    nums[j]=nums[j+1];
                }
                nums[l-1]=0;
            }
            else{
                i++;
            }
            k++;
        }

    }
};