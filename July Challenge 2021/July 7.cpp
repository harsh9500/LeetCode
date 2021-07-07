class Solution {
public:
    // void display(priority_queue<int> pq)
    // {
    //     priority_queue<int> pq_temp=pq;
    //     while(!pq.empty())
    //     {
    //         cout<<pq.top()<<" ";
    //         pq.pop();
    //     }
    //     cout<<endl;
    // }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> pq;
        int n=matrix.size();
        if(n==0)
            return 0;
        int m=matrix[0].size();
        if(m==0)
            return 0;
        int temp=k,flag=0;
        int i_start=n,j_start=m;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(temp==0)
                {
                    i_start=i;
                    j_start=j;
                    flag=1;
                    break;
                }
                pq.push(matrix[i][j]);
                temp--;
            }
            if(flag==1)
                break;
        }
        for(int i=i_start;i<n;i++)
        {
            int j;
            if(i==i_start)
                j=j_start;
            else
                j=0;
            for(;j<m;j++)
            {
                if(pq.top()>matrix[i][j])
                {
                    pq.pop();
                    pq.push(matrix[i][j]);
                }
            }
        }
        return pq.top();
    }
};