CC = gcc
CFLAGS = -Iinclude -Wall -Wextra -g

SRCS = src/Bubble_sort.c src/Selection_sort.c src/Insertion_sort.c src/Merge_sort.c src/Quick_sort.c main/main.c
OBJS = $(SRCS:.c=.o)

EXEC = teste

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(EXEC)

.PHONY: all clean

