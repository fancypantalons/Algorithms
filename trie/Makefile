CXXFLAGS=-std=c++0x -g -Wall

all: trie

trie: trie.o main.o
	$(CXX) trie.o main.o -o trie

trie.o: trie.cpp trie.h
main.o: main.cpp trie.h

clean:
	rm -f *.o trie
