all: task3

run:
	./hello3

task3: hello_ariel.h main1_3.c lib
	gcc main1_3.c -fPIC -ldl -o hello3

lib: hello_ariel.c hello_ariel.h
	gcc -shared hello_ariel.c -fPIC -o libhello.so

clean:
	-rm hello3 libhello.so
