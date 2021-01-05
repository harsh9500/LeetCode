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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode* sentinel = new ListNode(0,head);
        ListNode* res=sentinel;
        while(head)
        {
            if(head->next && head->val==head->next->val)
            {
                while(head->next && head->val==head->next->val)
                {
                    head=head->next;
                }
                res->next=head->next;
            }
            else
            {
                res=res->next;
            }
            head=head->next;
        }
        return sentinel->next;
    }
};