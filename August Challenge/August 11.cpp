class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n=citations.size();
        if(n==0)
            return 0;
        vector<int> bucket(n+1,0);
        for(int i=0;i<n;i++)
        {
            if(citations[i]<=n)
                bucket[citations[i]]++;
            else
                bucket[n]++;
        }
        int papers=0;
        for(int i=n;i>=0;i--)
        {
            papers+=bucket[i];
            if(papers>=i)
                return i;
        }
        return 0;        
    }
};