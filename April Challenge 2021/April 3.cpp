class Solution {
public:
    int longestValidParentheses(string s) {
        int answer=0;
        int n=s.length();
        if(n==0)
            return answer;
        // stack<int> st;
        // st.push(-1);
        // for(int i=0;i<n;i++)
        // {
        //     if(s[i]=='(')
        //     {
        //         st.push(i);
        //     }
        //     else
        //     {
        //         int index=st.top();
        //         st.pop();
        //         if(st.empty())
        //         {
        //             st.push(i);
        //         }
        //         else
        //         {
        //             answer=max(answer,i-st.top());
        //         }
        //     }
        // }
        int left=0, right=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
                left++;
            else
                right++;
            if(left==right)
                answer=max(answer,left*2);
            if(right>left)
                left=0,right=0;
        }
        left=0,right=0;
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]=='(')
                left++;
            else
                right++;
            if(left==right)
                answer=max(answer,left*2);
            if(left>right)
                left=0,right=0;
        }
        return answer;
    }
};