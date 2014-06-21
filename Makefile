GCC := g++
CFLAGS := -std=c++0x -g
INCLUDE= -I.

all: chess

chess: main.o printer.o
	$(GCC) -o chess $(CFLAGS) $^

%.o: %.cc *.h
	$(GCC) -c $(CFLAGS) $< -o $@

clean:
	rm -rf *.o chess
