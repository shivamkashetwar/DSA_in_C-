class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;
        bool iscycle = false;

        // Phase 1: Detect if a cycle exists
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast){
                iscycle = true;
                break;
            }
        }

        // If no cycle was found, return NULL
        if(!iscycle){
            return NULL;
        }

        // Phase 2: Find the start of the cycle
        slow = head;
        while(fast != slow){
            slow = slow->next;
            fast = fast->next;
        }
        
        return slow;
    }
};