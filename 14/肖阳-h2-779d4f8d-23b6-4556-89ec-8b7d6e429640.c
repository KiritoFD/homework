struct ListNode* reverse(struct ListNode* head){
    struct ListNode *tmp,*current=head,*prev=NULL;
    while (current){
        tmp=prev;prev=current->next;current->next=tmp;//current->next points to prev
        tmp=prev;prev=current;current=tmp;//swap prev and current
    }
    return prev;
}

struct ListNode* removeNodes(struct ListNode* head) {
    head=reverse(head);
    struct ListNode* p=head;
    while(p!=NULL &&p->next!=NULL){
        if(p->val>p->next->val){
            p->next=p->next->next;
        }
        else p=p->next;
    }
    return reverse(head);
}