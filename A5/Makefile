OBJS = a5.o runner.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -pedantic -ansi -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

a5: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o runner

runner.o: runner.cpp
	$(CC) $(CFLAGS) runner.cpp

a5.o: a5.cpp
	$(CC) $(CFLAGS) a5.cpp

clean:
	rm -rf *~ *.o runner

