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
    ListNode* merge(ListNode* h1, ListNode* h2) {
        ListNode* head = new ListNode(-1001);
        ListNode* temp = head;
        while(h1!=NULL && h2!=NULL) {
            if(h2->val > h1->val) {
                ListNode* curr = new ListNode(h1->val);
                temp->next = curr;
                temp = temp->next;
                h1 = h1->next;
            }
            else if(h2->val <= h1->val) {
                ListNode* curr = new ListNode(h2->val);
                temp->next = curr;
                temp = temp->next;
                h2 = h2->next;
            }
        }
        if(h1!=NULL)
            temp->next = h1;
        if(h2!=NULL)
            temp->next = h2;
        return head->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n==0)
            return NULL;
        ListNode* head = lists[0];
        for(int i=1;i<n;i++) {
            head = merge(head,lists[i]);
        }
        return head;
    }
};
