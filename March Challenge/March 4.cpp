/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* f=headA;
        ListNode* s=headB;
        while(f!=s)
        {
            f=f==NULL?headB:f->next;
            s=s==NULL?headA:s->next;
        }
        return f;
    }
};