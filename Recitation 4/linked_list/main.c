#include <stdio.h>
#include "list.h"

void print_list(node* head);

int main()
{
    /* head pointer for the list */
    node* head = NULL; 
    

    // 1
    add_head(1, &head);
    // 1 1
    add_head(1, &head);
    // 1 1 1
    add_head(1, &head);
    // 1 1 1 1
    add_head(1, &head);
    
    //inserts the value (first int param)
    //at the specified position (second int param, position starts from 0(head))
    
    //this command, since the position specified is 0 (head)
    //is equivalent to add_head(3, &head)
    // 2 1 1 1 1
    insert_at(2, 0, &head);
    print_list(head);
    //this command, since the position specified is 3
    // 2 1 1 3 1 1
    insert_at(3,3,&head);
    print_list(head);
  

    //this should remove the node in 3 position (which has value of 3)
    // 2 1 1 1 1
    remove_at(3, &head);
    print_list(head);


    //since position specified is 0 (head)
    //this is equivalent to remove_head
    // 1 1 1 1
    remove_at(0, &head);
    print_list(head);
    


    return 0;
}

void print_list(node* head) {
    node* current = head;
    while (current != NULL)
    {
        printf ("%d  ", current->value);
        current = (node*) current->next;
    }
    printf("\n");
}