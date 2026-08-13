class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int l=nums.size();
        int i,j=0,k=0,s=nums[0];
        vector<int>a;

        for(i=1;i<l;i++){
            if(nums[i]==nums[i-1]+1){
                s=s+nums[i];
            }
            else{
             
                break;
            }
        }
        while (find(nums.begin(), nums.end(), s) != nums.end()) {
            s++;
        }
        return s;
        
    }
};