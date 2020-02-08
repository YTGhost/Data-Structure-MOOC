#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *List;
struct Node
{
    ElementType Coe;
    ElementType Ind;
    List Next;
};

void init(List *a)
{
    *a = (List)malloc(sizeof(struct Node));
    int N;
    scanf("%d", &N);
    List t = *a;
    t->Next = NULL;
    if (N == 0)
    {
        t->Coe = 0;
        t->Ind = 0;
    }
    while (N--)
    {
        scanf("%d %d", &t->Coe, &t->Ind);
        if (t->Coe == 0 && t->Ind == 0)
        {
            continue;
        }
        if (N == 0)
        {
            break;
        }
        t->Next = (List)malloc(sizeof(struct Node));
        t = t->Next;
        t->Next = NULL;
    }
}

void out(List *a)
{
    List t = *a;
    while (t != NULL)
    {
        if (t->Next == NULL)
        {
            printf("%d %d\n", t->Coe, t->Ind);
            break;
        }
        printf("%d %d ", t->Coe, t->Ind);
        t = t->Next;
    }
}

List Add(List *a, List *b)
{
    List t1 = *a;
    List t2 = *b;

    List L = (List)malloc(sizeof(struct Node));
    L->Coe = 0;
    L->Ind = 0;
    List t3 = L;
    t3->Next = NULL;

    if (t1->Coe == 0 && t1->Ind == 0 && t2->Coe == 0 && t2->Ind == 0)
    {
        t3->Coe = 0;
        t3->Ind = 0;
    }

    while (t1 != NULL && t2 != NULL)
    {
        if (t1->Coe == 0 && t1->Ind == 0)
        {
            t1 = NULL;
            break;
        }

        if (t2->Coe == 0 && t2->Ind == 0)
        {
            t2 = NULL;
            break;
        }

        if (t1->Ind > t2->Ind)
        {
            t3->Coe = t1->Coe;
            t3->Ind = t1->Ind;
            t1 = t1->Next;
            t3->Next = (List)malloc(sizeof(struct Node));
            t3 = t3->Next;
        }
        else if (t1->Ind < t2->Ind)
        {
            t3->Coe = t2->Coe;
            t3->Ind = t2->Ind;
            t2 = t2->Next;
            t3->Next = (List)malloc(sizeof(struct Node));
            t3 = t3->Next;
        }
        else
        {
            if (t1->Coe + t2->Coe == 0)
            {
                t1 = t1->Next;
                t2 = t2->Next;
                t3->Next = NULL;
                continue;
            }
            t3->Coe = t1->Coe + t2->Coe;
            t3->Ind = t1->Ind;
            t3->Next = NULL;

            t1 = t1->Next;
            t2 = t2->Next;
            if (t1 == NULL && t2 == NULL)
            {
                break;
            }
            if (t1 == NULL || t2 == NULL)
            {
                t3->Next = (List)malloc(sizeof(struct Node));
                t3 = t3->Next;
                break;
            }
            if (t1->Coe + t2->Coe == 0)
            {
                continue;
            }
            t3->Next = (List)malloc(sizeof(struct Node));
            t3 = t3->Next;
        }
    }
    if (t1 == NULL)
    {
        while (t2 != NULL)
        {
            t3->Coe = t2->Coe;
            t3->Ind = t2->Ind;
            t2 = t2->Next;
            if (t2 == NULL)
            {
                t3->Next = NULL;
                break;
            }
            t3->Next = (List)malloc(sizeof(struct Node));
            t3 = t3->Next;
        }
    }
    else
    {
        while (t1 != NULL)
        {
            t3->Coe = t1->Coe;
            t3->Ind = t1->Ind;
            t1 = t1->Next;
            if (t1 == NULL)
            {
                t3->Next = NULL;
                break;
            }
            t3->Next = (List)malloc(sizeof(struct Node));
            t3 = t3->Next;
        }
    }
    return L;
}

List Multiple(List *a, List *b)
{
    List t1 = *a;
    List t2 = *b;
    List L = NULL;

    if ((t1->Coe == 0 && t1->Ind == 0) || (t2->Coe == 0 && t2->Ind == 0))
    {
        L = (List)malloc(sizeof(struct Node));
        L->Coe = 0;
        L->Ind = 0;
        L->Next = NULL;
        return L;
    }

    while (t1 != NULL)
    {
        List t = (List)malloc(sizeof(struct Node));
        List temp = t;
        while (t2 != NULL)
        {
            temp->Coe = 0;
            temp->Ind = 0;
            temp->Next = NULL;

            temp->Coe = t1->Coe * t2->Coe;
            temp->Ind = t1->Ind + t2->Ind;
            t2 = t2->Next;
            if (t2 == NULL)
            {
                break;
            }
            temp->Next = (List)malloc(sizeof(struct Node));
            temp = temp->Next;
        }
        L = Add(&t, &L);

        t1 = t1->Next;
        if (t1 == NULL)
        {
            break;
        }
        t->Next = (List)malloc(sizeof(struct Node));
        t = t->Next;
        t2 = *b;
    }
    return L;
}

int main()
{
    List a, b, mul, sum;
    init(&a);
    init(&b);
    mul = Multiple(&a, &b);
    sum = Add(&a, &b);
    out(&mul);
    out(&sum);
    system("pause");
    return 0;
}