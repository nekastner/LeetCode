#include <stddef.h>
#include <string.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

static struct ListNode* swap_pair(struct ListNode* head) {

    if (head == NULL || head->next == NULL) {
        return NULL;
    }

    struct ListNode* buffer[3];
    buffer[0] = head;
    buffer[1] = buffer[0]->next;
    buffer[2] = buffer[1]->next;

    buffer[1]->next = buffer[0];
    if (buffer[2] != NULL && buffer[2]->next != NULL) {
        buffer[0]->next = buffer[2]->next;
    }

    return buffer[2];
}

static struct ListNode* swapPairs(struct ListNode* head)
{
    struct ListNode* head_new = head->next; // head will be swapped with node 2 (index 1)

    struct ListNode* curr = head;
    while (curr != NULL) {
        curr = swap_pair(curr);
    }

    return head_new;
}

// TODO: solve