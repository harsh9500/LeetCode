// class Solution {
// public:
//     string addBinary(string a, string b) {
//         string answer="";
//         int n=a.length();
//         int m=b.length();
//         char carry='0';
//         while(n>0 && m>0)
//         {
//             char A=a[n-1];
//             char B=b[m-1];
//             if(A==B)
//             {
//                 if(A=='0')
//                 {
//                     if(carry=='1')
//                     {
//                         answer="1"+answer;
//                         carry='0';
//                     }
//                     else
//                     {
//                         answer="0"+answer;
//                     }
//                 }
//                 else
//                 {
//                     if(carry=='1')
//                     {
//                         answer="1"+answer;
//                     }
//                     else
//                     {
//                         answer="0"+answer;
//                     }
//                     carry='1';
//                 }
//             }
//             else
//             {
//                 if(carry=='1')
//                 {
//                     answer="0"+answer;
//                     carry='1';
//                 }
//                 else
//                 {
//                     answer="1"+answer;
//                 }
                
//             }
//             n--;
//             m--; 
//         }
//         while(m>0)
//         {
//             char B=b[m-1];
//             if(B=='0')
//             {
//                 if(carry=='0')
//                 {
//                     answer="0"+answer;
//                 }
//                 else
//                 {
//                     answer="1"+answer;
//                     carry='0';
//                 }
//             }
//             else
//             {
//                 if(carry=='0')
//                 {
//                     answer="1"+answer;
//                 }
//                 else
//                 {
//                     answer="0"+answer;
//                 }
//             }
//             m--;
//         }
//         while(n>0)
//         {
//             char A=a[n-1];
//             if(A=='0')
//             {
//                 if(carry=='0')
//                 {
//                     answer="0"+answer;
//                 }
//                 else
//                 {
//                     answer="1"+answer;
//                     carry='0';
//                 }
//             }
//             else
//             {
//                 if(carry=='0')
//                 {
//                     answer="1"+answer;
//                 }
//                 else
//                 {
//                     answer="0"+answer;
//                 }
//             }
//             n--;
//         }
//         if(carry=='1')
//                 answer="1"+answer;
//         return answer;
//     }
// };

class Solution {
public:
    string addBinary(string a, string b) {
        string answer="";
        int i=a.length()-1, j=b.length()-1,carry=0;
        while(i>=0 || j>=0)
        {
            int sum=carry;
            if(i>=0)
            {
                sum+=a[i]-'0';
                i--;
            }
            if(j>=0)
            {
                sum+=b[j]-'0';
                j--;
            }
            answer+=char(sum%2+'0');
            carry=sum/2;
        }
        if(carry!=0)
            answer+=char(carry+'0');
        reverse(answer.begin(),answer.end());
        return answer;
    }
};