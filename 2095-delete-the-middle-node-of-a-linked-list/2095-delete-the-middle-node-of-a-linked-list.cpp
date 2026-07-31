class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {

        // Edge Case
        if (head == NULL || head->next == NULL)
            return NULL;

        ListNode* prev = NULL;
        ListNode* slow = head;
        ListNode* fast = head;

        // Find Middle
        while (fast != NULL && fast->next != NULL) {

            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // Delete Middle Node
        prev->next = slow->next;
        delete slow;

        return head;
    }
};