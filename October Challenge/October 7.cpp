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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* temp=head;
        int noOfNodes=0,noOfNodesToSkip;
        while(temp!=NULL)
        {
            noOfNodes++;
            temp=temp->next;
        }
        if(noOfNodes==0 || noOfNodes==1)
            return head;
        k=k%noOfNodes;
        if(k==0)
            return head;
        noOfNodesToSkip=noOfNodes-k;
        ListNode* pretemp;
        ListNode* currtemp;
        pretemp=head;temp=head->next;
        for(int i=0;i<noOfNodesToSkip-1;i++)
        {
            pretemp=pretemp->next;
            temp=temp->next;
        }
        pretemp->next=NULL;
        currtemp=temp;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=head;
        head=currtemp;
        return head;
    }
};