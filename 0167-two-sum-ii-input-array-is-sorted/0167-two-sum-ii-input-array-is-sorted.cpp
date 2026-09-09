class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i,j,s=0;
        i=0;
        j=numbers.size()-1;
        vector<int> a;
        while(i<j){
            s= numbers[i]+numbers[j];
            if(s==target){
                a.push_back(i+1);
                a.push_back(j+1);
                break;
            }
            else if(s>target){ 
                 j--;
            }
            else{ 
                i++;
            }
        }
        return a;
    }
};