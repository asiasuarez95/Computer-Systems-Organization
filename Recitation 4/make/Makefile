Files:= foo.c main.c

Obj:= foo.o main.o

%.o : %.c
	gcc -c $(Files)

foo : $(Obj)
	gcc $^ -o foo

clean :
	rm $^ .o foo