class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i,j;
        vector<int> a;
        for(i=0;i<m;i++){
                nums1[i]=nums1[i];
        }
        int k=0;
        while(n!=0){
            nums1[m]=nums2[k];
            n--;
            m++;
            k++;
        }
        sort(nums1.begin(),nums1.end());
    }
};