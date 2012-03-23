.PHONY: all clean

all: vm.so test.s driver.out

vm.so: vm.cpp vm.h
	g++ -shared -std=c++0x $< -o $@

test.s: test.c
	gcc -S -masm=intel $< -o $@

driver.out: driver.cpp
	g++ -std=c++0x $< vm.so -I./ -o $@

clean:
	rm -f *.so *.s *.out 
