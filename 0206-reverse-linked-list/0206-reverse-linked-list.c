/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *p = NULL;
    struct ListNode *t = head;
    while(t){
        struct ListNode *n = t->next;
        t->next=p;
        p=t;
        t=n;
    }
    return p;
}