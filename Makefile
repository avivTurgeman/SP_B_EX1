#!make -f

#CXX=clang++-9 
CXX=gcc
CXXFLAGS= -Wall -g

HEADERS=AdptArray.h book.h Person.h
OBJECTS=AdptArray.o book.o Person.o
SOURCES=AdptArray.c book.c Person.c

run: demo
	./$^

mem_test: demo
	valgrind ./$^

demo: Demo.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o demo

%.o: %.c $(HEADERS)
	$(CXX) $(CXXFLAGS) --compile $< -o $@

clean:
	rm -f *.o demo
