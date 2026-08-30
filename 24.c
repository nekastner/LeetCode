#include <string.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

static struct ListNode* swapPairs(struct ListNode* head)
{
    // if there is no valid pair of nodes
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    // create head mock so there is a pre pair node for the first pair
    struct ListNode head_mock;
    head_mock.val = -1;
    head_mock.next = head;

    // start iterating over node pairs
    struct ListNode* pre_pair_node = &head_mock;
    while (pre_pair_node != NULL && pre_pair_node->next != NULL && pre_pair_node->next->next != NULL)
    {
        // buffer addresses of both pair nodes
        struct ListNode* pair_node_1 = pre_pair_node->next;
        struct ListNode* pair_node_2 = pair_node_1->next;

        // TODO: swap them in memory

        // swap pair nodes via pointer changes
        pre_pair_node->next = pair_node_2;
        pair_node_1->next = pair_node_2->next;
        pair_node_2->next = pair_node_1;

        // iterate to node before next pair
        pre_pair_node = pair_node_1; // pair node 1 is now pair node 2 (after swap)
    }

    // return next of head mock (actual new head)
    return head_mock.next;
}