class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i,j;
        int min=prices[0],profit=0;
        for(i=1;i<prices.size();i++){
            min = prices[i]<min?prices[i]:min;
            profit = profit>(prices[i]-min)?profit:(prices[i]-min);
        }
        return profit;
    }
};