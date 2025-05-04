#yaeldorani@gmail.com

CXX = clang++
CXXFLAGS = -std=c++11 -Wall -Wextra
TARGET = Main
TEST_TARGET = test
OBJS = main.o SquareMat.o
TEST_OBJS = test.o SquareMat.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

main.o: main.cpp SquareMat.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

test.o: test.cpp SquareMat.hpp
	$(CXX) $(CXXFLAGS) -c test.cpp

SquareMat.o: SquareMat.cpp SquareMat.hpp
	$(CXX) $(CXXFLAGS) -c SquareMat.cpp

test: $(TEST_OBJS)
	$(CXX) $(CXXFLAGS) -o $(TEST_TARGET) $(TEST_OBJS)
	./$(TEST_TARGET)

valgrind: test
	valgrind --leak-check=full ./$(TEST_TARGET)

clean:
	rm -f $(TARGET) $(TEST_TARGET) *.o
