CC = gcc -Wall -Werror -fsanitize=address
RM = rm -f

all: fileCompressor

fileCompressor: fileCompressor.c
	$(CC) -o fileCompressor fileCompressor.c

clean:
	$(RM) *.o
