Recitation 9: Stack Discipline and Stack Frames
==========

Read the C program in `ex1.c`.  The function `insert` inserts a node into the linked list such that 
the overall linked list is sorted in ascending order.
```c
//insert node n into the (ascending) sorted linked list 
// whose head pointer is pointed to by headp
void
insert(node **headp, node *n)
{
	char buf[100];
	node *head = *headp;
	//if head is null, make n the new head
	if (!head) { 
		n->next = NULL;
		*headp = n;

	//if head's value is bigger than n, insert n in front of head 
	}else if (head->v > n->v) { 
		n->next = head;
		*headp = n;
	
	//if head's value is smaller than n, recurse
	}else { 
		
		insert(&head->next, n);
	}
}
```

The `main` function inserts `iter` number of nodes into a linked list in _two_ ways (corresponding to 
the two `for` loop code blocks)

```c
int 
main(int argc, char **argv)
{
	...
	//insert iter nodes into a linked list
	node *head = NULL;
	for (int i = iter; i >= 0; i--) {
		node *n = (node *)malloc(sizeof(node));
		n->v = i;
		insert(&head, n);
	}
	...
	//insert iter nodes into another linked list
	head = NULL;
	for (int i = 0; i <= iter; i++) {
		node *n = (node *)malloc(sizeof(node));
		n->v = i;
		insert(&head, n);
	}
	...
}
```

Compile and run the program by typing 
```
$ gcc  -std=c99 -g -fno-stack-protector -fomit-frame-pointer ex1.c
```
Now run the program and insert different number of nodes into the linked list.
```
$ ./a.out 10
successfully inserted 10 nodes to linked list
successfully inserted 10 nodes again to linked list
$ ./a.out 1000
successfully inserted 1000 nodes to linked list
successfully inserted 1000 nodes again to linked list
$ ./a.out 100000
successfully inserted 100000 nodes to linked list
Segmentation fault

```

Answer the following questions, using gdb.
- Please explain this output.  Which instruction caused the program to incur a segmentation fault? Why?
- Calculate the size of each stack frame. Run the command `ulimit -a` in the terminal to figure out the stack size limit. Using some back-of-the-envelope-calculation, what is the smallest `iter` that you would expect the program to encounter a segmentation fault?  Does the actual execution match your calculation?

You will find the following commands useful (you do not necessarily have to use all of them to get the answers):

- Make use of the 'backtrace' command. A backtrace is a summary of how your program got where it is. It shows one line per frame, for many frames, starting with the currently executing frame (frame zero), followed by its caller (frame one), and on up the stack. 

```
	backtrace n
	bt n 
```

The above usage of 'backtrace' shows the innermost n frames (or the n most recent frames).

- You can "step into" a function i.e. to monitor the instructions being executed in that function in gdb. Use the command:

```
	si
	stepi 

	si n
	stepi n
```

'si' is similar to 'nexti' in that it executes the next machine instruction. The difference is that if the next instruction is a function call, gdb execution enters the function and stops, returning control to gdb. Providing an argument n results in continued execution in step for n many instructions.

Put your answers into a file named 'answers.txt' and push it to your repository.
