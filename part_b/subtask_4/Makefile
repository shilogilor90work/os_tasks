all: task1 task2 task3

task1: App1.c process1.c process2.c
	gcc -o App1 App1.c
	gcc -o process1 process1.c
	gcc -o process2 process2.c

task2: App2.c
	gcc -o App2 App2.c

task3:App3.c
	gcc -o App3 App3.c

run:
	./App4

clean:
	-rm App1 App2 App3 process1 process2
