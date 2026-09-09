class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
       int i,j,l,m,n,c=0;
       l=timeSeries.size();
       m=timeSeries[0];
        n=timeSeries[0]+duration-1;
       for(i=1;i<l;i++ ){
         c=c+(n-m+1);
        if(timeSeries[i]<=n){
           int k= n- timeSeries[i]+1;
            c=c-k;
        }
        m=timeSeries[i];
        n=timeSeries[i]+duration-1;
       }
       c=c+(n-m+1);
       return c;
    }  
};                                                                                                                                             
                                                                                                                                                                                                                                                                             