CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -O2
TARGET = matrix_calculator
SOURCES = src/main.cpp src/matrix.cpp
TESTS = src/test.cpp src/matrix.cpp

all: $(TARGET) test

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCES)

test: $(TESTS)
	$(CXX) $(CXXFLAGS) -o matrix_tests $(TESTS)

clean:
	rm -f $(TARGET) matrix_tests

.PHONY: all clean test