all: task1

task1: App.c process1.c process2.c
	gcc -o App App.c
	gcc -o process1 process1.c
	gcc -o process2 process2.c

run:
	./App

clean:
	-rm app process1 process2
