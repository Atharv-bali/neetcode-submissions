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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode (-1);
        ListNode* curr = dummy;
        ListNode* head = dummy;
        int carry=0;
        while(l1!=NULL || l2!=NULL) {
            int x = (l1==NULL)?0:l1->val;
            int y = (l2==NULL)?0:l2->val;
            ListNode* node = new ListNode((x+y+carry)%10);
            carry = (x+y+carry)/10;
            curr->next = node;
            curr = curr->next;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        if(carry) {
            curr->next = new ListNode(carry);
            curr = curr->next;
            curr->next= NULL;
        }
        return head->next;
    }
};
