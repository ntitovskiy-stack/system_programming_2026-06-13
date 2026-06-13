all: exe
	
exe: solution.c
	gcc solution.c -o solution
clean:
	rm -f solution
