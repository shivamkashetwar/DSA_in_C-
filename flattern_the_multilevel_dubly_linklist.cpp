class Solution {
public:
    Node* flatten(Node* head) {
        if (head == NULL) {
            return head;
        }
        
        Node* curr = head; // Fixed: 'node' to 'Node'
        while (curr != NULL) {
            if (curr->child != NULL) {
                Node* next = curr->next; // Fixed: 'node' to 'Node'
                curr->next = flatten(curr->child);
                
                curr->next->prev = curr;
                curr->child = NULL;
                
                // Traverse to the end of the newly attached flattened child list
                while (curr->next != NULL) {
                    curr = curr->next;
                }
                
                // Reattach the original next node
                if (next != NULL) {
                    curr->next = next;
                    next->prev = curr;
                }
            }
            curr = curr->next;
        }
        
        return head;
    }
};