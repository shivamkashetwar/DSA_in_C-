class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL){
            return NULL;
        }
        
        unordered_map<node*,node*>m;
        
        node* newhead=new node(head->val);
        node* oldtemp=head->next;
        node* newtemp=newhead;
        m[head]=newhead;
        
        while(oldtemp!=NULL){
            node* copynode=new node(oldtemp->val);
            m[oldtemp]=copynode;
            newtemp->next=copynode;
            
            oldtemp=oldtemp->next;
            newtemp=newtemp->next;
            
        }
        
        oldtemp=head,newtemp=newhead;
        while(oldtemp!=NULL){
            newtemp->random=m[oldtemp->random];
            
                oldtemp=oldtemp->next;
            newtemp=newtemp->next;
            
            
        }
        
        return newhead;
        
        
        
    }
};