class Solution {
public:
    int scoreOfParentheses(string S) {
//         stack<int> s;
//         s.push(0);

//         for(char c:S)
//         {
//             if (c=='(')
//                 s.push(0);
//             else
//             {
//                 int v=s.top();
//                 s.pop();
//                 int w=s.top();
//                 s.pop();
//                 s.push(w + max(2*v, 1));
//             }
//         }
//         return s.top();
        
        int ans=0, bal=0;
        for (int i=0;i<S.length();i++)
        {
            if(S[i]=='(')
            {
                bal++;
            }
            else
            {
                bal--;
                if (S[i-1]=='(')
                    ans+=(1<<bal);
            }
        }
        return ans;
    }
};