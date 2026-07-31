class Solution {
public:

    // Reverse Linked List
    ListNode* reverse(ListNode* head) {

        ListNode* prev = NULL;
        ListNode* curr = head;

        while (curr != NULL) {

            ListNode* nextNode = curr->next;

            curr->next = prev;

            prev = curr;
            curr = nextNode;
        }

        return prev;
    }

    void reorderList(ListNode* head) {

        if (head == NULL || head->next == NULL)
            return;

        // Step 1 : Find Middle
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {

            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2 : Reverse Second Half
        ListNode* second = reverse(slow->next);

        // Break the list into two halves
        slow->next = NULL;

        // Step 3 : Merge both halves
        ListNode* first = head;

        while (second != NULL) {

            ListNode* firstNext = first->next;
            ListNode* secondNext = second->next;

            first->next = second;
            second->next = firstNext;

            first = firstNext;
            second = secondNext;
        }
    }
};