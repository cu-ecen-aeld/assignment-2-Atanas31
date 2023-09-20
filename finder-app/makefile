native: CC=gcc
native: writer.o
	$(CC) -o writer writer.o

CROSS_COMPILE: CC=aarch64-none-linux-gnu-gcc
CROSS_COMPILE: writer.o
	$(CC) -o writer writer.o

.PHONY: clean

clean:
	rm -f writer 
	rm -f *.o

