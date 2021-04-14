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
    ListNode* partition(ListNode* head, int x) {
        if(!head)
            return head;
        ListNode* smallTemp = new ListNode(-101);
        ListNode* bigTemp = new ListNode(-101);
        ListNode* small = new ListNode(-101,smallTemp);
        ListNode* big = new ListNode(-101,bigTemp);
        while(head)
        {
            ListNode* temp = new ListNode(head->val);
            if(head->val<x)
            {
                smallTemp->next=temp;
                smallTemp=temp;
            }
            else
            {
                bigTemp->next=temp;
                bigTemp=temp;
            }
            head=head->next;
        }
        smallTemp->next=big->next->next;
        return small->next->next;
    }
};