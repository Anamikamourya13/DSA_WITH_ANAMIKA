void reverse(ListNode* head, int times) {
    ListNode* curr = head;
    ListNode* prev = nullptr;

    while (times--) {
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
}

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {

        if (head == nullptr)
            return head;

        ListNode* left = head;
        ListNode* right;
        ListNode* res = nullptr;
        ListNode* prevleft = nullptr;
        ListNode* nextleft = nullptr;

        int size = 2;

        while (true) {

            right = left;

            for (int i = 0; i < size - 1; i++) {
                if (right == nullptr)
                    break;

                right = right->next;   
            }

            if (right) {

                nextleft = right->next;

                reverse(left, size);

                if (prevleft)
                    prevleft->next = right;

                prevleft = left;

                if (res == nullptr)
                    res = right;

                left = nextleft;
            }
            else {

                if (prevleft)
                    prevleft->next = left;

                if (res == nullptr)
                    res = left;

                break;   
            }
        }

        return res;
    }
};