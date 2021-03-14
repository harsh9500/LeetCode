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
    ListNode* swapNodes(ListNode* head, int k) {
        vector<int> v;
        ListNode* iter=head;
        while(iter)
        {
            v.push_back(iter->val);
            iter=iter->next;
        }
        swap(v[k-1],v[v.size()-k]);
        ListNode * temp = new ListNode();
        temp->val=v[0];
        head=temp;
        for(int i=1;i<v.size();i++)
        {
            ListNode * t=new ListNode();
            t->val=v[i];
            temp->next=t;
            temp=t;
        }
        return head;
    }
};