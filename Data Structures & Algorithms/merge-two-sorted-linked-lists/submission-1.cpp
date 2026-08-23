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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* p1 = list1;
        ListNode* p2 = list2;

        ListNode* curr = nullptr;
        ListNode* head = nullptr;
        while (p1 || p2) {
            if (!p2 || (p1 && p1->val < p2->val)) {
                if (curr) {
                    curr->next = p1;
                    curr = curr->next;
                } else {
                    curr = p1;
                    head = curr;
                }
                p1 = p1->next;
            }
            else {
                if (curr) {
                    curr->next = p2;
                    curr = curr->next;
                } else {
                    curr = p2;
                    head = curr;
                }
                p2 = p2->next;
            }
        }
        return head;
    }
};
