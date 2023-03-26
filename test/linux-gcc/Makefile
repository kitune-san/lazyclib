TARGET	= test-linux-gcc
CC			= gcc
CFLAGS	= -ffreestanding -nostartfiles -W -Wall
INCLUDE	= -I../../include -I../TesUT
SOURCES	= test.c ../../src/string.c ../test_string.c ../TesUT/tesut.c ../TesUT/additions/tesut-console.c ../TesUT/additions/tesut-lib.c
OBJS	= $(notdir $(SOURCES:.c=.o))

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJS): $(SOURCES)
	$(CC) $(CFLAGS) $(INCLUDE) -c $(SOURCES)

clean:
	rm -f $(OBJS) $(TARGET)

