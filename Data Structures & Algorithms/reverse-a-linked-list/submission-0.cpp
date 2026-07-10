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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* later = head;
        while(head) {
            later = later->next;
            head->next = prev;
            prev = head;
            head = later;
        }
        return prev;
    }
};
//Time complexity: O(n)
//Space complexity: O(1)