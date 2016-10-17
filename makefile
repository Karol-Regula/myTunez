list: list.c list.h
	gcc list.c -o list

run: list
	./list

clean:
	rm *~
