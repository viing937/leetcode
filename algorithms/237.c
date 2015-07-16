#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

void deleteNode(struct ListNode* node)
{
    struct ListNode *toDel = node->next;
    node->val = node->next->val;
    node->next = node->next->next;
    free(toDel);
    return;
}

int main()
{
    return 0;
}
