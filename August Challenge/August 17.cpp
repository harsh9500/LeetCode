class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> answer(num_people,0);
        int n=0,i,temp,flag=0;
        while(flag==0)
        {
            for(i=0;i<num_people;i++)
            {
                temp=n*num_people+i+1;
                if(candies>=temp)
                {
                    answer[i]+=temp;
                    candies-=temp;
                }
                else
                {
                    flag=1;
                    break;
                }
            }
            n++;
        }
        answer[i]+=candies;
        return answer;
    }
};