all: pd

pdm:main.o personaldiary.o
	gcc -Wall -o pd main.o personaldiary.o

main.o:main.c
	gcc -c -Wall main.c

personaldiarymanagement.o:personaldiary.c
	gcc -c -Wall personaldiary.c
