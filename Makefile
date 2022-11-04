CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
OBJFILES = comparing_functions.o dir_functions.o order_functions.o printing_functions.o get_args.o go_ls.o main.o 
EXECFILE = my_ls

all: $(EXECFILE)

$(EXECFILE): $(OBJFILES)
	$(CC) $(CFLAGS) $(OBJFILES) -o $(EXECFILE)

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $^

.PHONY: clean

clean:
	rm -f $(EXECFILE) *.o
