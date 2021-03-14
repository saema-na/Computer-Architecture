CC = g++
OBJ = main.o
EXE = main

main: $(OBJ)
	$(CC) $(OBJ) -o $(EXE) $(LIBS)

main.o: main.c
	$(CC) -c main.c -o main.o

clean:
	\rm *.o *~ $(EXE)
