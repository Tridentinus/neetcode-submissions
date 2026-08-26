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
    int pairSum(ListNode* head) {
        // get N 
        ListNode* curr = head;
        int N =0;
        while (curr) {
            N++;
            curr = curr->next;
        }

        ListNode* slow = head;
        // traverse to head of half 2
        ListNode* fast = head;
        for (int i =0; i < N/2; i++) {
            fast = fast->next;
        }


        // reverse linked list
        ListNode* prev = nullptr;
        curr = fast;
        while (curr) {
            auto next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // two pointer walk along the first half and reversed second half
        fast = prev;
        int res = 0;
        for (int i =0; i < N/2; i++) {
            int sum = slow->val + fast->val;
            res = max(res,sum);
            slow = slow->next; fast = fast->next;
        }

        return res;
    }
};