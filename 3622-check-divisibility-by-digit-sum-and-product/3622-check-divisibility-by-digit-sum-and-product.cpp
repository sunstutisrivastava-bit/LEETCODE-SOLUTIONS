class Solution {
public:
    bool checkDivisibility(int n) {
        int m=1,s=0;
        int a=n;
        while(a>0){
            int r=a%10;
            s=s+r;
            m=m*r;
            a=a/10;
        }
        if(n%(m+s)==0){
            return true;
        }
        return false;
    }
};