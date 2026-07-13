class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if (head == nullptr || left == right)
            return head;

        ListNode* t = head;
        ListNode* before = nullptr;
        int pos = 1;

        // Reach the left position
        while (pos < left) {
            before = t;
            t = t->next;
            pos++;
        }

        // Reverse the sublist
        ListNode* start = t;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;

        while (pos <= right) {
            next = t->next;
            t->next = prev;
            prev = t;
            t = next;
            pos++;
        }

        // Reconnect the reversed part
        if (before != nullptr)
            before->next = prev;
        else
            head = prev;

        start->next = t;

        return head;
    }
};