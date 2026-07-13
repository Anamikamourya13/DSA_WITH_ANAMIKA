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
    ListNode* reverseKGroup(ListNode* head, int k) {
      if (head == nullptr)
            return head;

        ListNode* left = head;
        ListNode* right;
        ListNode* res = nullptr;
        ListNode* prevleft = nullptr;
        ListNode* nextleft = nullptr;

        int size = k;

        while (true) {

            right = left;

            for (int i = 0; i < size - 1; i++) {
                if (right == nullptr)
                    break;

                right = right->next;   // <-- ye missing tha
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

                break;     // <-- ab ye while ke andar hai
            }
        }

        return res;
    }
};  