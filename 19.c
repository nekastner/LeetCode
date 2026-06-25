#include <stddef.h>

// TODO: review

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    // if list.length <= 1
    if (head == NULL || head->next == NULL) return NULL;
    // else
    struct ListNode* toDeletePrevious = NULL; // node in front of <node to delete>
    const struct ListNode* current = head; // current node on iteration
    int list_length = 0;
    while (current != NULL) {
        list_length++; // increment list length counter
        if (list_length == n+1) toDeletePrevious = head;
        else if (list_length > n) toDeletePrevious = toDeletePrevious->next;
        current = current->next; // jump into next node
    }
    // if first element shall be removed
    if (list_length == n) {
        struct ListNode* head_new = head->next; // save new head
        head->next = NULL; // remove link to list in <node to delete>
        return head_new;
    }
    // else
    struct ListNode* toDelete = toDeletePrevious->next; // save <node to delete>
    toDeletePrevious->next = toDelete->next; // remove link in list to <node to delete>
    toDelete->next = NULL; // remove link to list in <node to delete>
    return head;
}
