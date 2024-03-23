/*
给定一个链表，如果有环路，找出环路的开始点。
142. Linked List Cycle II(Medium)
*/
#include <cstdio>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *detectCycle(ListNode *head)
{
    ListNode *slow = head, *fast = head;
    // 判断是否存在环路
    do
    {
        if (!fast || !fast->next)
            return nullptr;
        fast = fast->next->next;
        slow = slow->next;
    } while (fast != slow);
    // 如果存在，查找环路节点
    fast = head;
    while (fast != slow)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return fast;
}

int main()
{
    ListNode *head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    head->next->next->next->next = head->next;
    ListNode *result = detectCycle(head);
    printf("环路开始点的值为%d\n", result->val);
    return 0;
}