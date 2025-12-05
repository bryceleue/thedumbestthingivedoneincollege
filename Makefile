CXX=g++
CXXFLAGS=-g

BINARIES=tests

all: $(BINARIES)

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $^

tests: tests.o testing.o int_array_3d.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -f $(BINARIES) *.o
