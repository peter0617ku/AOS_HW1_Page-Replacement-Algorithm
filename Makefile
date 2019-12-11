all: function.o FIFO.o optimal.o ESC.o M083040024.o MyAlgorithm.o
	gcc -o M083040024 function.o FIFO.o optimal.o ESC.o M083040024.o MyAlgorithm.o
function.o:
	gcc -c function.c
FIFO.o:
	gcc -c FIFO.c
optimal.o:
	gcc -c optimal.c
ESC.o:
	gcc -c ESC.c
M083040024.o:
	gcc -c M083040024.c

MyAlgorithm.o:
	gcc -c MyAlgorithm.c
clean:
	rm M083040024 M083040024.o FIFO.o optimal.o ESC.o function.o MyAlgorithm.o

