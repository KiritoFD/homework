/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    if(!head||!k||!head->next) return head;
    
    struct ListNode* last=head,*start=head,*ans;
    int count=1;
    while(last->next!=NULL){
        count++;
        last=last->next;
    }
    k=k%count;
    if(k==0) return head;
    for(int i=1;i<count-k;i++){
        start=start->next;
    }
    ans=start->next;
    last->next=head;
    start->next=NULL;
    return ans;
    }