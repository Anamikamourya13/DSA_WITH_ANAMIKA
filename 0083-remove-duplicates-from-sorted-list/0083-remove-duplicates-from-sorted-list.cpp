class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {

        // Empty list ya sirf ek node
        if(head == NULL || head->next == NULL)
            return head;

        ListNode* current = head;

        while(current != NULL && current->next != NULL){

            // Duplicate mila
            if(current->val == current->next->val){
                current->next = current->next->next;
            }
            // Duplicate nahi mila
            else{
                current = current->next;
            }
        }

        return head;
    }
};
    