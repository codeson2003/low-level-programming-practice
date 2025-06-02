# Compiler and flags
CC = gcc
CFLAGS = -Wall -g

# Object files
OBJS = main.o parser.o executor.o

# Output binary
TARGET = cwe-shell

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

main.o: main.c parser.h executor.h
	$(CC) $(CFLAGS) -c main.c

parser.o: parser.c parser.h
	$(CC) $(CFLAGS) -c parser.c

executor.o: executor.c executor.h
	$(CC) $(CFLAGS) -c executor.c

clean:
	rm -f *.o $(TARGET)
