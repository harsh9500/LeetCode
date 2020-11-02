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
    ListNode* insertionSortList(ListNode* head) {
        if(!head)
            return NULL;
        ListNode* newHead=new ListNode();
        ListNode* temp=head;
        ListNode* prevNode;
        ListNode* nextNode;
        ListNode* dummy;
        while(temp!=NULL)
        {
            prevNode=newHead;
            nextNode=newHead->next;
            while(nextNode!=NULL)
            {
                if(temp->val<nextNode->val)
                    break;
                prevNode=nextNode;
                nextNode=nextNode->next;
            }
            dummy=temp->next;
            temp->next=nextNode;
            prevNode->next=temp;
            temp=dummy;
        }
        return newHead->next;
    }
};