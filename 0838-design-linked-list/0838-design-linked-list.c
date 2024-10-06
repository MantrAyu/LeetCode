struct listnode {
    int val;
    struct listnode* prev;
    struct listnode* next;
};

typedef struct listnode listnode;

listnode* newlistnode(listnode* prev,int val,listnode* next) {
    listnode* new = malloc(sizeof(listnode));
    new->prev = prev;
    new->val = val;
    new->next = next;
    return new;
}

typedef struct {
    int len;
    struct listnode* head;
    struct listnode* tail;
} MyLinkedList;


MyLinkedList* myLinkedListCreate() {
    MyLinkedList* obj = malloc(sizeof(MyLinkedList));
    obj->head = NULL;
    obj->tail = NULL;
    obj->len = 0;
    return obj;
}

int myLinkedListGet(MyLinkedList* obj, int index) {
    if (index >= obj->len)
        return -1;
    if (index == obj->len-1)
        return obj->tail->val;
    listnode* head = obj->head;
    for (int i = 0;i < index; i++)
        head = head->next;
    return head->val;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    if (obj->len == 0) 
        obj->head = obj->tail = newlistnode(NULL,val,NULL);
    else {
        obj->head = newlistnode(NULL,val,obj->head);
        obj->head->next->prev = obj->head;
    }
    obj->len++;
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    if (obj->len == 0) 
        obj->head = obj->tail = newlistnode(NULL,val,NULL);
    else {
        obj->tail = newlistnode(obj->tail,val,NULL);
        obj->tail->prev->next = obj->tail;
    }
    obj->len++;
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if (index == 0)
        myLinkedListAddAtHead(obj,val);
    else if (index == obj->len)
        myLinkedListAddAtTail(obj,val);
    else if (index > obj->len) 
        return;
    else {
        listnode* head = obj->head;
        for (int i = 0; i < index; i++) {
            head = head->next;
        }
        head->prev->next = newlistnode(head->prev,val,head);
        head->prev = head->prev->next;
        obj->len++;
    }
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if (index >= obj->len)
        return;
    if (index == 0) {
        obj->head = obj->head->next;
    }
    else if (index == obj->len-1) {
        obj->tail = obj->tail->prev;
    }
    else {
        listnode* head = obj->head;
        for (int i = 0; i < index; i++)
            head = head->next;
        head->prev->next = head->next;
        head->next->prev = head->prev;
    }
    obj->len--;
}

void myLinkedListFree(MyLinkedList* obj) {
    free(obj->head);
    free(obj);
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 
 * myLinkedListAddAtHead(obj, val);
 
 * myLinkedListAddAtTail(obj, val);
 
 * myLinkedListAddAtIndex(obj, index, val);
 
 * myLinkedListDeleteAtIndex(obj, index);
 
 * myLinkedListFree(obj);
*/