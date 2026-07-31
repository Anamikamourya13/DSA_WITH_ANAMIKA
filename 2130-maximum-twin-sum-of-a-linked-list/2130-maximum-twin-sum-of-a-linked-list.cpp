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

    int pairSum(ListNode* head) {

        // Step 1 : Find Middle
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {

            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2 : Reverse Second Half
        ListNode* second = reverse(slow);

        // Step 3 : Find Maximum Twin Sum
        ListNode* first = head;

        int maxSum = 0;

        while (second != NULL) {

            int sum = first->val + second->val;

            maxSum = max(maxSum, sum);

            first = first->next;
            second = second->next;
        }

        return maxSum;
    }
};