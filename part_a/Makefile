all: task1 task2 task3

run:
	./hello1
	./hello2
	./hello3

task1: hello_ariel.c hello_ariel.h main1_1.c
	gcc -o hello1 hello_ariel.c main1_1.c

task2: hello_ariel.h main1_1.c lib
	gcc main1_1.c -L. -l hello -o hello2

task3: hello_ariel.h main1_3.c lib
	gcc main1_3.c -fPIC -ldl -o hello3

lib: hello_ariel.c hello_ariel.h
	gcc -shared hello_ariel.c -fPIC -o libhello.so

clean:
	-rm hello1 hello2 hello3 libhello.so
