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
    ListNode* reverse(ListNode* head)
    {
        ListNode* prev=NULL;
        ListNode* next=NULL;
        ListNode* curr=head;
        while(curr!=NULL)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1=reverse(l1);
        l2=reverse(l2);
        ListNode* result1=l1;
        ListNode* result2=l2;
        int sum,carry=0;
        while(l1 && l2)
        {
            sum=(l1->val+l2->val+carry);
            l1->val=sum%10;
            l2->val=sum%10;
            carry=sum/10;
            l1=l1->next;
            l2=l2->next;
        }
        if(l1)
        {
            while(l1)
            {
                sum=(l1->val+carry);
                l1->val=sum%10;
                carry=sum/10;
                l1=l1->next;
            }
            result1=reverse(result1);
            if(carry)
            {
                ListNode* carryPtr=new ListNode(carry,result1);
                return carryPtr;
            }
            return result1;
        }
        else
        {
            while(l2)
            {
                sum=(l2->val+carry);
                l2->val=sum%10;
                carry=sum/10;
                l2=l2->next;
            }
            result2=reverse(result2);
            if(carry)
            {
                ListNode* carryPtr=new ListNode(carry,result2);
                return carryPtr;
            }
            return result2;
        }
        return NULL;
    }
};