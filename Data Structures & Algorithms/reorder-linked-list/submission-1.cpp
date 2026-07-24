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
    ListNode* reverse(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* prev = NULL, *ptr1;
        while(head) {
            ptr1 = head->next;
            head->next = prev;
            prev = head;
            head = ptr1;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        ListNode* slow=head, *fast = head;
        while(fast!=NULL && fast->next!=NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* rev = reverse(slow);
        ListNode* curr = head;
        ListNode* temp;
        while(rev->next!=NULL) {
            ListNode* tempprev = rev->next;
            temp = curr->next;
            curr->next = rev;
            rev->next = temp;curr = temp;
            rev = tempprev;
        }
        return;
    }
};
