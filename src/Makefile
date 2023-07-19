CC = gcc
CFLAGS = -Wall -Wextra -std=c99
LDFLAGS = -lm

SRCS = main.c ray.c vec3.c objects.c

all: main

main: $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o main $(LDFLAGS)

clean:
	rm -f main

.PHONY: all clean