all: exe

exe: main.c
  gcc main.c -o solution
clean:
  -rm solution 2>/dev/null
