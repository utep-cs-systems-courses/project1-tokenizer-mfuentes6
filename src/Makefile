# -g to debug -O3 to optimize code performance
CFLAGS= -g -O3

all: tokenize

tokenizer.o: tokenizer.h
history.o: history.c

tokenize: tokenizer.o history.o uimain.o
	cc -o tokenize $ tokenizer.o history.o uimain.o
clean:
	rm -f *.o tokenize
run: tokenize
	./tokenize
