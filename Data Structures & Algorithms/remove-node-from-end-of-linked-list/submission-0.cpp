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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count=0;
        ListNode* list = head, * prev=NULL;
        while(list) {
            count++;
            list = list->next;
        }
        list = head;
        for(int i=0;i<count-n;i++) {
            prev=list;
            list = list->next;
        }
        if(prev==NULL)
            return head->next;
        prev->next = list->next;
        list->next=NULL;
        return head;
    }
};
