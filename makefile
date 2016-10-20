compile: main.c list.c list.h songLib.c songLib.h
	gcc main.c songLib.c list.c -o myTunez

run: compile
	./myTunez

clean:
	rm *~
