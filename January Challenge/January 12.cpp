/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1->val==0 && !l1->next)
            return l2;
        if(l2->val==0 && !l2->next)
            return l1;
        int carry=0;
        ListNode* temp1=l1;
        ListNode* temp2=l2;
        ListNode* pre1;
        ListNode* pre2;
        while(l1 && l2)
        {
            int s=l1->val + l2->val + carry;
            carry=s/10;
            s=s%10;
            l1->val=s;
            l2->val=s;
            pre1=l1;
            pre2=l2;
            l1=l1->next;
            l2=l2->next;
        }
        if(!l2)
        {
            if(carry!=0)
            {
                while(l1 && carry!=0)
                {
                    int s=l1->val + carry;
                    carry=s/10;
                    s=s%10;
                    l1->val=s;
                    pre1=l1;
                    l1=l1->next;
                }
                if(carry!=0)
                {
                    pre1->next=new ListNode(carry);
                }
            }
            return temp1;
        }
        if(!l1)
        {
            if(carry!=0)
            {
                while(l2 && carry!=0)
                {
                    int s=l2->val + carry;
                    carry=s/10;
                    s=s%10;
                    l2->val=s;
                    pre2=l2;
                    l2=l2->next;
                }
                if(carry!=0)
                {
                    pre2->next=new ListNode(carry);
                }
            }
            return temp2;
        }
        
        return temp1;
    }
};