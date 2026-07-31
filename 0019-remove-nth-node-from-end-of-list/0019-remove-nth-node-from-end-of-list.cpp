class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        // Step 1 : Create Dummy Node
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        // Step 2 : Initialize Fast & Slow
        ListNode* slow = dummy;
        ListNode* fast = dummy;

        // Step 3 : Move Fast (n + 1) steps
        for (int i = 0; i <= n; i++) {
            fast = fast->next;
        }

        // Step 4 : Move both pointers
        while (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }

        // Step 5 : Delete the node
        ListNode* temp = slow->next;
        slow->next = temp->next;
        delete temp;

        // Step 6 : Return Answer
        return dummy->next;
    }
};