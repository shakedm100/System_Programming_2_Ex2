#shaked1mi@gmail.com

CXX = g++
CXXFLAGS = -std=c++11 -Wall -I. -Iunits

COMMON_SOURCES = matrix.cpp

MAIN_SOURCES = main.cpp $(COMMON_SOURCES)

TEST_SOURCES = test.cpp $(COMMON_SOURCES)

MAIN_OBJS = $(MAIN_SOURCES:.cpp=.o)
TEST_OBJS = $(TEST_SOURCES:.cpp=.o)

TARGET_MAIN = main
TARGET_TEST = test

# Build main executable
main: $(MAIN_OBJS)
	$(CXX) $(MAIN_OBJS) -o $(TARGET_MAIN)

# Build test executable
test: $(TEST_OBJS)
	$(CXX) $(TEST_OBJS) -o $(TARGET_TEST)

# compile .cpp to .o files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run valgrind on the test executable
valgrind: test
	valgrind --leak-check=full ./$(TARGET_TEST)

clean:
	rm -f $(MAIN_OBJS) $(TEST_OBJS) $(TARGET_MAIN) $(TARGET_TEST)

.PHONY: main test clean valgrind
