class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int l,i,j;
        l= nums.size();
        int max,min,c=INT_MAX,p=-1;
        max=nums[0],min=nums[0];
        for(i=0;i<l;i++){
            max=nums[i]>max?nums[i]:max;
            min=nums[i];
            for(j=i;j<l;j++){
                min=nums[j]<min?nums[j]:min;
            }
            cout<<max<<" "<<min<<endl;
            if(max-min<=k){
                if((max-min)<c){
                c=max-min;
                p=i;
                break;
                }
            }
        }
        return p;
    }
};