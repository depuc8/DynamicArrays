CC = cc
CFLAGS = -std=c11 -Wall -Wextra -Wpedantic -O2

TARGET = DynA

SRCS = ./src/DynA.c ./src/main.c 
OBJS = DynA.o main.o

.PHONY:all clean

all:$(TARGET)

$(TARGET):$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

DynA.o: ./src/DynA.c ./src/DynA.h

	$(CC) $(CFLAGS) -c ./src/DynA.c
main.o: ./src/main.c ./src/DynA.h

	$(CC) $(CFLAGS) -c ./src/main.c

clean:
	rm -f $(OBJS) $(TARGET)
