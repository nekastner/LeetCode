#include <string.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

static struct ListNode* swapPairs(struct ListNode* head)
{
    struct ListNode* indirect = head;

    while (indirect != NULL && indirect->next != NULL)
    {
        // swap pair
        struct ListNode* temp = indirect->next;
        indirect->next = temp->next;
        temp->next = indirect;
        // iterate to next pair
        indirect = indirect->next;
    }

    return head;
}

// TODO: solve (pairs do not point to each other properly anymore, is in-memory swap okay?)