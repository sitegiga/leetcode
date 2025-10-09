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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        ListNode dummy(0, head);
        ListNode *prev = &dummy, *end = head;

        while (true) {
            for (int i = 1; i < k && end; ++i) end = end->next;
            if (!end) break;

            ListNode *start = prev->next;
            ListNode *nextGroup = end->next;
            end->next = nullptr;

            prev->next = reverseList(start);
            start->next = nextGroup;

            prev = start;
            end = prev->next;
        }
        return dummy.next;
    }

private:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        while (head) {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
};