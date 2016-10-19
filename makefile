list: list.c list.h
	gcc list.c -o myTunez

run: list
	./myTunez

clean:
	rm *~
