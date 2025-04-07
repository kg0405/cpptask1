#kfirgafni2005@gmail.com

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g
VALGRIND_FLAGS = --leak-check=full

TARGET = Main
TEST_TARGET = testtask1
SOURCES = taske1.cpp
TEST_SOURCES = testtask1.cpp

all: $(TARGET) $(TEST_TARGET)

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCES)

$(TEST_TARGET): $(TEST_SOURCES)
	$(CXX) $(CXXFLAGS) -o $(TEST_TARGET) $(TEST_SOURCES)

run: $(TARGET)
	./$(TARGET)

test: $(TEST_TARGET)
	./$(TEST_TARGET)

valgrind: $(TARGET)
	valgrind $(VALGRIND_FLAGS) ./$(TARGET)

clean:
	rm -f $(TARGET) $(TEST_TARGET)
