/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteMiddle(struct ListNode* head) {
    if(head->next == NULL)
       return NULL;
    struct ListNode *curr = head;
    int c = 0;
    while(curr != NULL){
         curr = curr->next;
         c++;
    }
    curr = head;
    for(int i=0; i<c/2-1; i++)
       curr= curr->next;
    struct ListNode *q = curr->next;
    curr->next = curr->next->next;
    free(q);
    return head;
}