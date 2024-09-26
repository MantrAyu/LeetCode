/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode *a=head;
    while(a != NULL && a->next != NULL){
        if(a->val==a->next->val)
           a->next=a->next->next;
        else
           a=a->next;
    }
    return head;
}