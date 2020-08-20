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
    void reorderList(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return;
        ListNode *ptr1=head;
        ListNode *ptr2=head;
        while(ptr2->next && ptr2->next->next)
        {
            ptr1=ptr1->next;
            ptr2=ptr2->next->next;
        }
        ListNode * preMiddle=ptr1;
        ListNode * preCurrent=ptr1->next;
        while(preCurrent->next)
        {
            ListNode * preNext=preCurrent->next;
            preCurrent->next=preNext->next;
            preNext->next=preMiddle->next;
            preMiddle->next=preNext;
        }
        ptr1=head;
        ptr2=preMiddle->next;
        while(ptr1!=preMiddle)
        {
            preMiddle->next=ptr2->next;
            ptr2->next=ptr1->next;
            ptr1->next=ptr2;
            ptr1=ptr2->next;
            ptr2=preMiddle->next;
        }
    }
};