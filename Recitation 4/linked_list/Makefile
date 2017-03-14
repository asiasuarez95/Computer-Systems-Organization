Files:= list.c main.c

Obj:= list.o main.o

Head := list.h

%.o : %.c $(Head)
	gcc -c $(Files)

list : $(Obj)
	gcc $^ -o list

clean :
	rm $^ .o list