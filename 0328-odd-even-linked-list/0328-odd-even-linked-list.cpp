class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {

        // Base case
        if(head == nullptr || head->next == nullptr)
            return head;

        ListNode* odd = head;          // Odd position
        ListNode* even = head->next;   // Even position
        ListNode* evenHead = even;     // Save even head

        while(even != nullptr && even->next != nullptr) {

            odd->next = even->next;    // Connect odd nodes
            odd = odd->next;

            even->next = odd->next;    // Connect even nodes
            even = even->next;
        }

        odd->next = evenHead;          // Join both lists

        return head;
    }
};