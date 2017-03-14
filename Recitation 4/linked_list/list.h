typedef struct
{
    int value;
    struct node* next;
} node;

/* Adds a new head */
void add_head(int value, node** head);

/* Inserts a new node at specified position */
/* void insert_at(...) */
void insert_at(int value, int position, node** head);

/* Removes the head */
void remove_head(node** head);

/* Remove element at specified position */
/* void remove_at(...); */
void remove_at(int position, node** head);
