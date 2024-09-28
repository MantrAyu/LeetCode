/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *revl(struct ListNode *head){
    struct ListNode *prev= NULL ,*curr =head ,*next=NULL;
    while( curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
bool isPalindrome(struct ListNode* head) {
    if(head == NULL || head->next == NULL)
        return true;
    struct ListNode *slow = head , *fast = head;
    while(fast != NULL && fast->next !=NULL){
         slow = slow->next;
         fast = fast->next->next;
    }
    struct ListNode *sh = revl(slow);

    struct ListNode *fh= head, *sh1= sh;
    bool p = true;
    while(sh1 != NULL){
        if(fh->val != sh1->val){
            p = false;
            break;
        }
        fh= fh->next;
        sh1= sh1->next;
    }
    return p;
}