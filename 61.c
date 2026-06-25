#include <stddef.h>

// TODO: review

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* rotateRight(struct ListNode* head, int k) {

    // if list is empty
    if (head == NULL) {
        return head;
    }

    // check length and make tail point to head (so list stays complete after shifting head)
    int len = 1;
    struct ListNode* tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
        len++;
    }
    k %= len;
    tail->next = head;

    // find new head and make new tail point to null
    struct ListNode* new_tail = head;
    for (int i = 0; i < len - k; i++) {

        if (i >= 1) {
            new_tail = new_tail->next;
        }

        head = head->next;
    }
    new_tail->next = NULL;

    // return new head
    return head;
}