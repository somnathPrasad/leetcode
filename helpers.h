#ifndef HELPERS_H
#define HELPERS_H

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <string>
#include <functional>
#include <stack>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printVector(const vector<int> &vec)
{
    for (const auto &val : vec)
    {
        cout << val << " ";
    }
    cout << endl;
}

void printBoolVector(const vector<bool> &vec)
{
    for (const auto &val : vec)
    {
        if (val == 1)
            cout << "true" << " ";
        else
            cout << "false" << " ";
    }
    cout << endl;
}

void print2DVector(const vector<vector<int>> &vec)
{
    for (const auto &row : vec)
    {
        for (const auto &val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }
}

void printList(ListNode *head)
{
    ListNode *temp = head;
    while (temp)
    {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

#endif // HELPERS_H
