#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void add_head(int value, node** head)
{
    /* allocate memory for storing the node */
    node* n = (node*) malloc(sizeof(node));
    /* Make sure that the memory was allocated, if not, just quit */
    if (n == NULL)
        exit(1);
    n->value = value;
    n->next = (struct node*) (*head);
    (*head) = n;
}

void remove_head(node** head)
{
    /* Check if the list is empty */
    if (head == NULL )
        return;
    /* Get the pointer to the first element  */
    node* n = *head;
    /* Advance head  */
    (*head) = (node*) n->next;
    //free the memory location, as we are no longer using the memory.
    free(n);
}

//insert a new node at a specified position with a specified value
//position starts from head (0), next (1), next (2), and so on
void insert_at(int value, int position, node** head)
{
     /* allocate memory for storing the node */
    node* n = (node*) malloc(sizeof(node));
    /* Make sure that the memory was allocated, if not, just quit */
    if (n == NULL)
        exit(1);

    //if the user wants to add to the position 0 (head)
    if(position == 0)
    {
        //call add head method and return
        add_head(value, head);
        return;
    }


    //while loop to move current pointer to one noce before specified position
    node* cur = *head;

    while(cur != NULL && position > 1)
    {
        cur = (node*) cur->next;
        position --;
    }
    
    //if the while loop did not move to the proper position
    //this indicates that the linklist is shorter than the specified position
    if(position > 1)
    {
        //thus return
        printf("insert_at: position specified is invalid");
        return;
    }

    //assign value
    n->value = value;
    //let the n.next to point at cur.next
    n->next = cur->next;
    //finally, let the cur.next to point at n
    //we follow this order, in order to not lose the cur.next
    cur->next = (struct node*) n;
}


//remove the node at the specified position
void remove_at(int position, node** head)
{
    if (head == NULL)
        return;

    if(position == 0)
    {
        remove_head(head);
        return;
    }

    node* cur = *head;
    //move to one before the position intended to delete
    while(cur != NULL && position > 1)
    {
        cur = (node*) cur->next;
        position --;
    }
    
    //if the while loop did not move to the proper position
    //this indicates that the linked list is shorter than the position specified
    if(position > 1)
    {
        //thus return
        printf("remove_at: position specified is invalid");
        return;
    }
    
    node* del = (node*) cur->next;
    // Advance current
    cur->next = del -> next;
    //free the memory location, as we are no longer using the memory.
    free(del);
}


