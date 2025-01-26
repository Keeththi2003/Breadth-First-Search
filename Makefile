CC = gcc
CFLAGS = -g

TARGET = bfs
OBJ = main.o graph.o queue.o

build: $(TARGET)

$(TARGET): main.o graph.o queue.o
	$(CC) $(CFLAGS) -o $(TARGET) ${OBJ}

main.o: main.c graph.h queue.h
	$(CC) $(CFLAGS) -c main.c

graph.o: graph.c graph.h queue.h
	$(CC) $(CFLAGS) -c graph.c

queue.o: queue.c queue.h
	$(CC) $(CFLAGS) -c queue.c

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f ${OBJ} $(TARGET)
