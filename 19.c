#include <stddef.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, const int n)
{
    // move to index n if possible
    const struct ListNode* current_node = head;
    for (int i = 0; i < n; i++)
    {
        if (current_node == NULL) return NULL;
        current_node = current_node->next;
    }

    // if head should be deleted (because n equals the list length)
    if (current_node == NULL) return head->next;

    // iterate through list with distance n to the latest known node
    struct ListNode* prev_to_delete_node = head;
    while (current_node->next != NULL)
    {
        current_node = current_node->next;
        prev_to_delete_node = prev_to_delete_node->next;
    }

    // if tail should be deleted (because there is no node after the node to delete)
    if (prev_to_delete_node->next->next == NULL) prev_to_delete_node->next = NULL;
    // delete node at index n
    else prev_to_delete_node->next = prev_to_delete_node->next->next;

    return head;
}