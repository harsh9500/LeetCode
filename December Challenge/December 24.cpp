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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next)
            return head;
        
        // ListNode **pp = &head, *a, *b;
        // while ((a = *pp) && (b = a->next))
        // {
        //     a->next = b->next;
        //     b->next = a;
        //     *pp = b;
        //     pp = &(a->next);
        // }
        // return head;
        
        ListNode* newHead = new ListNode(-1);
        ListNode* prev = newHead;
        ListNode* cur = head;
        while (cur){
            if (!cur->next)
            {
                prev->next = cur;
                cur = cur->next;
            }
            else
            {
                ListNode* temp = cur->next->next;
                prev->next = cur->next; prev = prev->next;
                prev->next = cur; prev = prev->next;
                prev->next = nullptr;
                cur = temp;
            }
        }
        return newHead->next;
    }
};