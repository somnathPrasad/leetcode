#include "helpers.h"

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    ListNode *temp = nullptr;
    ListNode *head = nullptr;

    while (list1 && list2)
    {
        int val;
        if (list1->val > list2->val)
        {
            val = list2->val;
            list2 = list2->next;
        }
        else
        {
            val = list1->val;
            list1 = list1->next;
        }

        if (head == nullptr)
        {
            head = new ListNode(val);
            temp = head;
        }
        else
        {
            temp->next = new ListNode(val);
            temp = temp->next;
        }
    }

    while (list1)
    {
        int val = list1->val;
        list1 = list1->next;

        if (head == nullptr)
        {
            head = new ListNode(val);
            temp = head;
        }
        else
        {
            temp->next = new ListNode(val);
            temp = temp->next;
        }
    }

    while (list2)
    {
        int val = list2->val;
        list2 = list2->next;

        if (head == nullptr)
        {
            head = new ListNode(val);
            temp = head;
        }
        else
        {
            temp->next = new ListNode(val);
            temp = temp->next;
        }
    }

    return head;
}

int main()
{
    ListNode *list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);

    ListNode *list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    ListNode *merged = mergeTwoLists(list1, list2);
    cout << "merged: ";
    printList(merged);

    return 0;
}