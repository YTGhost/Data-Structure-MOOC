#include <iostream>

using namespace std;

typedef int ElementType;
struct ListNode
{
    ElementType val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL) {}
};

ListNode* init(int N)
{
    ListNode* dummyRoot = new ListNode(1);
    ListNode* ptr = dummyRoot;
    for (int i = 2; i <= N; i++)
    {
        ptr->next = new ListNode(i);
        ptr = ptr->next;
    }
    ptr->next = dummyRoot;
    return dummyRoot;
}

void deleteNode(ListNode* node)
{
    
}

int main()
{
    ListNode* node = init(10);
    ListNode* ptr = node;
    int number = 5;
    int i = 0;
    while(ptr->next!=ptr)
    {
        i++;
        if(i==5){
            cout << "编号为" << ptr->val << "的猴子出列" << endl;
            delete (ptr);
        }else{
            cout << "编号为" << ptr->val << "的猴子报数" << endl;
            ptr = ptr->next;
        }
    }

    system("pause");
    return 0;
}