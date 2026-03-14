# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++17 -Wall

# Executables
APP = calculator
TEST = test

# Source files
SRC = src/main.cpp src/calculator.cpp
TEST_SRC = src/calculator.cpp tests/test_calculator.cpp

# Default target
all: build

# Build the main calculator application
build:
	$(CXX) $(CXXFLAGS) $(SRC) -o $(APP)

# Run the calculator
run: build
	./$(APP)

# Compile and run unit tests
test:
	$(CXX) $(CXXFLAGS) $(TEST_SRC) -o $(TEST)
	./$(TEST)

# Clean generated files
clean:
	rm -f $(APP) $(TEST)