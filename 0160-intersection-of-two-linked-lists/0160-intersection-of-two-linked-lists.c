/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int gl(struct ListNode *head){
    int l=0;
    while (head != NULL){
        l++;
        head= head->next;
    }
    return l;
}

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
   if(!headA || !headB)
      return NULL;
   int la =gl(headA);
   int lb =gl(headB);

   while(la>lb){
      headA = headA->next;
      la--;
   }
   while(lb>la){
      headB = headB->next;
      lb--;
   }
   while(headA != headB){
      headA = headA->next;
      headB = headB->next;
   }
   return headA;
}