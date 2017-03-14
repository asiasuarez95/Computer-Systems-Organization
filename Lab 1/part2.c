#include <stdio.h>
#include <assert.h>

#include "part2.h"

// Don't remove these two lines!
extern struct list_node *alloc_node(void);
extern void free_node(struct list_node *node);

// Insert a new list node with the given value right after the
// specified node.
void list_insert(struct list_node *head, int value)
{
    assert(head != NULL);
    struct list_node* node = alloc_node();
    (*node).value = value;

    (*node).next = (*head).next;
    (*head).next = node;
}

// Return a pointer to the last node in a linked list, starting
// from the given head node.
struct list_node* list_end(struct list_node *head)
{
    assert(head != NULL);

    struct list_node* last = head;
    if((*head).next == NULL)
    {
        return head;
    }
    else
    {
        while((*last).next != NULL)
        {
            last= (*last).next;
        }
    }
    return last;
}

// Return the number of nodes in a linked list, starting from the
// given head pointer.
int list_size(struct list_node *head)
{
    assert(head != NULL);

    int count =1;
    while((*head).next != NULL)
    {
        count++;
        head = (*head).next;
    }
    return count;
}

// Return a pointer to the first node in the given linked list
// (starting at head) with the specified value, and store the pointer
// to its predecessor node at predp.
struct list_node * list_find(struct list_node *head, int value, struct list_node **predp)
{
    assert(head != NULL);
    assert(predp != NULL);

    if((*head).value == value)
    {
        *predp = NULL;
        return head;
    }

    while(head != NULL && (*head).value != value)
    {
        *predp = head;
        head = (*head).next;
    }

    if(head == NULL)
    {
        *predp = NULL;
        return NULL;
    }
    return head;
}

// Remove a node from the given linked list (starting at the given head)
// with the specified value.  Return 1 if a node was removed and 0
// otherwise.  If the node removed is the head node, then set the
// pointer to the head pointer to point to the new list head (which
// should be head->next).  Use free_node on the removed node.
//
// Note that instead of a pointer to a node, the passed head pointer "headp"
// is actually a pointer to a pointer.  To get the pointer to the head node,
// you will need to dereference it.  A pointer to a pointer is passed so
// that the value of the head node pointer can be changed if the head node
// is removed.
//
// As an example, consider the following linked list:
//
// |---------|      |---------|      |---------|
// |    0    |  /-> |    1    |  /-> |    2    |
// |---------| /    |---------| /    |---------|
// |       ----     |       ----     |   NULL  |
// |---------|      |---------|      |---------|
//
// If the head pointer refers to the node with the value 0 and
// list_remove(head, 1) is called, then the pointer to the head pointer
// should remain unchanged and the new linked list structure should
// be as follows:
//
// |---------|      |---------|
// |    0    |  /-> |    2    |
// |---------| /    |---------|
// |       ----     |   NULL  |
// |---------|      |---------|
//
// If we consider the original list, and list_remove(head, 0) is called,
// then the pointer to the head pointer should be set to the node
// with the value 1 and the new linked list structure should be as follows:
//
// |---------|      |---------|
// |    1    |  /-> |    2    |
// |---------| /    |---------|
// |       ----     |   NULL  |
// |---------|      |---------|
//
// Hint: Use list_find to get the node to remove and its predecessor,
// then manipulate the next pointers of the nodes to restructure the
// list.
// Hint: Don't forget to call free_node!
// Hint: Don't forget to set the new pointer to the head node if the
// head node is removed.
int list_remove(struct list_node **headp, int value)
{
    assert(headp != NULL);
    assert(*headp != NULL);

    // TODO: Your code here.
    assert(0);
    return 0;
}
