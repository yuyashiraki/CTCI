#include <stdio.h>
#include <stdlib.h>

typedef struct _Node
{
    int val;
    struct _Node *prev, *next;
} Node;

void addNode(Node** headAddr, int pos, int val)
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->prev = newNode->next = NULL;
    if (NULL == *headAddr) {
        if (0 == pos) {
            *headAddr = newNode;
        }
        return;
    }
    Node *ptr = *headAddr;
    while (NULL != ptr && pos--) ptr = ptr->next;
    if (pos > 0) return;
    newNode->prev = ptr;
    newNode->next = ptr->next;
    if (NULL != newNode->next) newNode->next->prev = newNode;
    ptr->next = newNode;
}

void deleteNode(Node** headAddr, int pos)
{
    if (NULL == *headAddr) return;
    Node *ptr = *headAddr;
    if (0 == pos) {
        *headAddr = ptr->next;
    }
    while (NULL != ptr && pos--) ptr = ptr->next;
    if (pos > 0 || NULL == ptr) return;
    if (ptr->prev) ptr->prev->next = ptr->next;
    if (ptr->next) ptr->next->prev = ptr->prev;
    free(ptr);
}

void printList(Node* head)
{
    if (head) {
        printf("%d", head->val);
        head = head->next;
    }
    while (head) {
        printf(" %d", head->val);
        head = head->next;
    }
    printf("\n");
}

int main(void)
{
    int T;
    scanf("%d", &T);
    while (T--) {
        int N;
        Node *head, *tail;
        head = tail = NULL;
        scanf("%d", &N);
        for (int i = 0; i < N; i++) {
            if (NULL == head) {
                head = tail = (Node*)malloc(sizeof(Node));
                tail->prev = tail->next = NULL;
            } else {
                tail->next = (Node*)malloc(sizeof(Node));
                tail->next->prev = tail;
                tail = tail->next;
                tail->next = NULL;
            }
            scanf("%d", &(tail->val));
        }
        int p, x;
//        scanf("%d %d", &p, &x);
//        addNode(&head, p, x);
        scanf("%d", &p);
        deleteNode(&head, p - 1);
        printList(head);
    }
    return 0;
}
