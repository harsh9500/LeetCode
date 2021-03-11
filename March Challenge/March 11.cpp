class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        if(n==0)
            return -1;
        int solution[amount+1];
        for(int i=0;i<=amount;i++)
            solution[i]=INT_MAX;
        solution[0]=0;
        for(int i=0;i<n;i++)
        {
            for(int j=coins[i];j<=amount;j++)
            {
                if(solution[j-coins[i]]!=INT_MAX)
                    if(1+solution[j-coins[i]]<solution[j])
                        solution[j]=1+solution[j-coins[i]];
            }
        }
        if(solution[amount]==INT_MAX)
            return -1;
        return solution[amount];
    }
};