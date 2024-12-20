/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* start=head;
    while(head&&head->next){
        if(head->next->val==head->val)
        head->next=head->next->next;//point to the next node
        else head=head->next;//move to the next node
    }
    return start;
}