#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *List;
struct Node
{
    ElementType Data;
    List Next;
};

void init(List *a)
{
    *a = (List)malloc(sizeof(struct Node));
    int i = 0;
    scanf("%d", &i);
    List t = *a;
    while (i != -1)
    {
        t->Data = i;
        t->Next = (List)malloc(sizeof(struct Node));
        t = t->Next;
        scanf("%d", &i);
    }
    t->Data = -1;
}

int main()
{
    int i, j;
    List a, b, c, t;
    init(&a);
    init(&b);
    c = (List)malloc(sizeof(struct Node));
    c->Next = NULL;
    t = c;

    if(a->Data == -1 && b->Data == -1){
        printf("NULL");
        return 0;
    }
    while(a->Data != -1 && b->Data != -1){
        if(a->Data <= b->Data){
            t->Data = a->Data;
            t->Next = (List)malloc(sizeof(struct Node));
            t = t->Next;
            t->Next = NULL;
            a = a->Next;
        }else{
            t->Data = b->Data;
            t->Next = (List)malloc(sizeof(struct Node));
            t = t->Next;
            t->Next = NULL;
            b = b->Next;
        }
        if(a->Data == -1 || b->Data == -1){
            break;
        }
    }

    if(a->Data == -1){
        while(b->Data != -1){
            t->Data = b->Data;
            b = b->Next;
            if(b->Data == -1){
                break;
            }
            t->Next = (List)malloc(sizeof(struct Node));
            t = t->Next;
            t->Next = NULL;
        }
    }else{
        while(a->Data != -1){
            t->Data = a->Data;
            a = a->Next;
            if(a->Data == -1){
                break;
            }
            t->Next = (List)malloc(sizeof(struct Node));
            t = t->Next;
            t->Next = NULL;
        }
    }
    while(c != NULL){
        if(c->Next == NULL){
            printf("%d", c->Data);
            break;
        }
        printf("%d ", c->Data);
        c = c->Next;
    }
    system("pause");
    return 0;
}