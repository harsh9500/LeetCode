class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        double m[101][101] = {0.0};
        m[0][0] = poured;
        for(int r=0; r<=query_row; r++)
        {
            for(int c=0;c<= r; c++)
            {
                double a= (m[r][c]-1.0)/2.0;
                if(a>0)
                {
                    m[r+1][c]+=a;
                    m[r+1][c+1]+=a;
                }
            }
        }
        if(m[query_row][query_glass]>1.0)
            return 1.0;
        else
            return m[query_row][query_glass];
    }
};