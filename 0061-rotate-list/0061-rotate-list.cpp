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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr)
        return nullptr;
        ListNode* last =  head;
        int n = 1;
        while(last-> next != nullptr){
            n++;
            last = last->next;
        }
        k= k%n;
        if(k==0)
           return head;

        ListNode* t= head;
        int count =1;

        while( t != nullptr)
        {
            if(count ==(n-k))
            break;

            count++;
            t=t->next;
        }
        last->next = head;
        ListNode* res = t->  next;
        t-> next = nullptr;
        return res;

    }
};