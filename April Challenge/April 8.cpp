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
    ListNode* middleNode(ListNode* head) {
        ListNode * temp= head;
        int count=0,index;
        while(temp!=NULL)
        {
            temp=temp->next;
            count++;
        }
        
        index=count/2;
        
        int i=0;
        temp=head;
        while(i<index)
        {
            temp=temp->next;
            i++;
        }
        return temp;
    }
};