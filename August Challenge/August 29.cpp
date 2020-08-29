class Solution {
public:
    int maximumElementIndex(vector<int>A, int n)
    {
        int index=0;
        for(int i=0;i<n;i++)
        {
            if(A[i]>A[index])
            {
                index=i;
            }
        }
        return index;
    }
    vector<int> pancakeSort(vector<int>& A) {
        int n=A.size();
        vector<int> answer;
        for(int i=n;i>1;i--)
        {
            int maxInd=maximumElementIndex(A,i);
            if(maxInd!=i-1)
            {
                answer.push_back(maxInd+1);
                reverse(A.begin(),A.begin()+maxInd+1);
                answer.push_back(i);
                reverse(A.begin(),A.begin()+i);
            }
        }
        
        return answer;
    }
};