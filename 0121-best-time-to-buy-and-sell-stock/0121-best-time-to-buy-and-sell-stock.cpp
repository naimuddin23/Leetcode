class Solution {
public:
    void solve(vector<int>&prices,int i,int& min,int& maxprofit)
{
    if(i>=prices.size())
    {
      return;
    }
    if(prices[i]<min)
    {
        min=prices[i];
    }
    int profit=prices[i]-min;
    if(profit>maxprofit)
    {
        maxprofit=profit;
    }
    solve(prices,i+1,min,maxprofit);
}
    int maxProfit(vector<int>& prices) {
        int min=INT_MAX;
        int maxprofit=INT_MIN;
        int i=0;
        solve(prices,i,min,maxprofit);
        return maxprofit;
        
    }
};