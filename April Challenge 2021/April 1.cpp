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
    ListNode* reverse(ListNode * head)
    {
        ListNode* prevPtr=NULL;
        ListNode* nextPtr=NULL;
        while(head)
        {
            nextPtr=head->next;
            head->next=prevPtr;
            prevPtr=head;
            head=nextPtr;
        }
        return prevPtr;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast && fast->next)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        if(fast)
            slow=slow->next;
        slow=reverse(slow);
            fast=head;
        while(slow)
        {
            if(fast->val!=slow->val)
                return false;
            fast=fast->next;
            slow=slow->next;
        }
        return true;
    }
};