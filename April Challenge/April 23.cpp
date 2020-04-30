class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if(m==0) return 0;
        int answer=0;
        int m_msb,n_msb,temp;
        while(m && n)
        {
            m_msb=(int)(log2(m));
            n_msb=(int)(log2(n));
            if(m_msb!=n_msb)
                break;
            temp=(1<<m_msb);
            answer+=temp;
            m-=temp;
            n-=temp;
        }
        return answer;
    }
};