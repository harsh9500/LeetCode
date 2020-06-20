class Solution {
public:
    string getPermutation(int n, int k) {
        // string s;
        vector<int> digits;
        vector<int> factorial(n+1);
        factorial[0]=1;
        for(int i=1;i<=n;i++)
        {
            // s+=to_string(i);
            digits.push_back(i);
            factorial[i]=factorial[i-1]*i;
        }
        
        // do{
        //     k-=1;
        //     if(k==0)
        //         return s;
        // }while(next_permutation(s.begin(),s.end()));
        
        string answer="";
        k-=1;
        
        for(int i=1;i<=n;i++)
        {
            int index=k/factorial[n-i];
            answer+=to_string(digits[index]);
            remove(digits.begin(),digits.end(),digits[index]);
            k-=index*factorial[n-i];
        }   
        
        return answer;
    }
};