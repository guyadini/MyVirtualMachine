.PHONY: all clean

all: vm.so test.s

vm.so : vm.cpp vm.h
	g++ -shared -std=c++0x $< -o $@

test.s: test.c
	gcc -S -masm=intel $< -o $@

clean:
	rm -f *.so *.s 
