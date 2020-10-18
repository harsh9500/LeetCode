class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        if(n<2 || k<1)
            return 0;
        if(k>n/2)
        {
            int maxProfit=0;
            for(int i=1;i<n;i++)
            {
                if(prices[i]>prices[i-1])
                    maxProfit+=prices[i]-prices[i-1];
            }
            return maxProfit;
        }
        int buy[k];
        for(int i=0;i<k;i++)
            buy[i]=INT_MIN;
        int sell[k];
        for(int i=0;i<k;i++)
            sell[i]=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<k;j++)
            {
                if(j==0)
                {
                    buy[j]=max(buy[j],-1*prices[i]);
                }
                else
                {
                    buy[j]=max(buy[j],sell[j-1]-prices[i]);
                }
                sell[j]=max(sell[j],buy[j]+prices[i]);
            }
        }
        return sell[k-1];
    }
};