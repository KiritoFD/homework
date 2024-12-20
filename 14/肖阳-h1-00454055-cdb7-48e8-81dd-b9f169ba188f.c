/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* middleNode(struct ListNode* head) {
    int count=0;
    struct ListNode* tmp=head;
    while(head->next){
        count++;
        head=head->next;
    }
    count=(count+1)/2;
    head=tmp;
    while(count--){
        head=head->next;
    }
    return head;
}