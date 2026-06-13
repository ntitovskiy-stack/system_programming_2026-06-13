all: exe
	
exe: main.c
	gcc main.c -o solution
clean:
	rm -f solution
