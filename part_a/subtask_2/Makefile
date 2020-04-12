all: task2

run:
	./hello2

task2: hello_ariel.h main1_1.c lib
	gcc main1_1.c -L. -l hello -o hello2

lib: hello_ariel.c hello_ariel.h
	gcc -shared hello_ariel.c -fPIC -o libhello.so

clean:
	-rm hello2 libhello.so
