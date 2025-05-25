# compiler
CXX = g++

# compiler options
CXXFLAGS = -g -std=c++17

# list .h files here
HEADERS = DNAStrand.h

# list .cpp files here
TEST_FILES = DNAStrand.cpp tests.cpp

.PHONY: all
all: tests.exe

.PHONY: tests.exe # Always force rebuild of tests
tests.exe: $(TEST_FILES) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(TEST_FILES) -o $@

.PHONY: clean
clean:
	rm -f *.o tests.exe
