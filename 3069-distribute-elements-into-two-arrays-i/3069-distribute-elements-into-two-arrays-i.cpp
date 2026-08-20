class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int l=nums.size();
        int i,j,n;
         vector<int>arr1;
         vector<int>arr2;
         n=l;
          arr1.push_back(nums[0]);
             arr2.push_back(nums[1]);
         for(i=2;i<l;i++){
               int l1=arr1.size();
         int l2=arr2.size();
         if(arr1[l1-1]>arr2[l2-1]){
            arr1.push_back(nums[i]);
         }
         else{
            arr2.push_back(nums[i]);
         }
         }
         arr1.insert(arr1.end(), arr2.begin(), arr2.end());
         return arr1;

    }
};